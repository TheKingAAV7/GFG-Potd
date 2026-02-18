

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int MAXI=1e4+1;
        vector<int>dp;
        vector<int>v;
        v.resize(MAXI,0);
        int B= ceil(sqrt(1.0*MAXI));
        int sz= ceil( (1.0*MAXI)/(1.0*B));
        dp.resize(sz,0);
        
        auto update=[&](int idx)->void{
            v[idx]++;
            int i= idx/B;
            dp[i]+=1;
            return;
        };
        
        auto query=[&](int lef, int rig)->int{
            if (lef > rig) return 0;          
            int lefi=lef/B;
            int rigi=rig/B;
            if(lefi==rigi){
                int sm=0;
                for(int i=lef;i<=rig;i++) sm+=v[i];
                return sm;
            }
            int sm=0;
            for(int i=lefi+1;i<rigi;i++) sm+=dp[i];
            
            int lstrt ,lend;
            lstrt= lef;
            lend = (lefi + 1) * B - 1;
            for(int i=lstrt;i<=lend;i++) sm+=v[i];
            int rstrt= rigi*B;
            int rend= rig;
            for(int i=rstrt;i<=rend;i++) sm+=v[i];
            return sm;
        };
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=query(arr[i]+1,MAXI-1);
            update(arr[i]);
            
            ans+=cnt;
        }
        return ans;
        
        
        
        
        
    }
};