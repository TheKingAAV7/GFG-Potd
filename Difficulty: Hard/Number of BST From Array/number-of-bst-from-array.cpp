class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        /*
        
         1 2 3 4 5 6 7 8 9
                5
              4    



        1 2 3

        
        state -> there's a root with [0,n-1]
        
        f(i)+=(0,i-1)*f(i+1,n-1)
        
        f(i+1) f(i-1)
        
        */
        
        auto f= [&](auto &&self, int i, int lef, int rig)->int{
            if(lef>rig) return 0;
            if(lef==rig) return 1;
            int tans1=0;
            int tans2=0;
            for(int j=lef;j<i;j++){
                tans1+=self(self,j,lef,i-1);
            }
            for(int j=i+1;j<=rig;j++){
                tans2+=self(self,j,i+1,rig);
            }
            // cout<<tans1<<" "<<tans2<<endl;
            if(tans2==0) return tans1;
            if(tans1==0) return tans2;
            return tans1*tans2;
        };
        int n=arr.size();
        vector<array<int,2>>a;
        for(int i=0;i<n;i++) a.push_back({arr[i],i});
        sort(a.begin(),a.end());
        vector<int>ans(n);
       
        for(int i=0;i<n;i++){
            int cur= f(f,i,0,n-1);
            
            ans[a[i][1]]=cur;
        }
        return ans;
        
    }
};