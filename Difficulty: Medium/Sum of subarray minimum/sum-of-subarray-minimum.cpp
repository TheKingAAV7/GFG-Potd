class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        stack<pair<int,int>>lef,rig;
        
        int n=arr.size();
        vector<int>v1(n,1),v2(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            while(!lef.empty() and arr[i]<=arr[lef.top().first]){
                cnt+=lef.top().second;
                lef.pop();
            }
            //cout<<i<<" "<<cnt+1<<endl;
            lef.push({i,cnt+1});
            v1[i]=cnt+1;
        }
        for(int i=n-1;i>=0;i--){
            
            int cnt=0;
            while(!rig.empty() and arr[i]<arr[rig.top().first]){
                cnt+=rig.top().second;
                rig.pop();
            }
         //   cout<<i<<" "<<cnt<<endl;
            rig.push({i,cnt+1});
            v2[i]=cnt+1;
        }
     //   for(int &i:v2) i-=1;
    //   for(int i:v1) cout<<i<<" ";
    //   cout<<endl; 
    //   for(int i:v2) cout<<i<<" ";
    //   cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            int left=v1[i];
            int right=v2[i];
            int tmp=(left+right-1)+((left-1)*(right-1));
         //   cout<<tmp<<endl;
            ans+=tmp*arr[i];
        }
        return ans;
    }
};