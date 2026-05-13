class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // aba#ababa+
        // 0 0 1 0  
        int n= a.size();
        int m= b.size();
        reverse(a.begin(),a.end());
        
        a.push_back(1e5);
        for(int i=m-1;i>=0;i--) a.push_back(b[i]);
        //  4 0 1 2 3
        //  a3 a2 a1 
        // 3 2 1 0 4
        // 4 0 1 2 3
        
        reverse(a.begin(),a.end());
        int sz= a.size();
        vector<int>z(sz,0);
        
        int lef=0,rig=0;
        for(int i=1;i<sz;i++){
            if(i<=rig){
                z[i]= min(rig-i+1,z[i-lef]);
            }
            while(a[z[i]]==a[i+z[i]]) z[i]++;
            
            if(i+z[i]-1>rig){
                lef=i;
                rig=i+z[i]-1;
            }
        }
        
        vector<int>ans;
        for(int i=m+1;i<sz;i++){
            if(z[i]==m) ans.push_back(i-m-1);
        }
       
        return ans;
        
    }
};