class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int m=arr.size();
        int n=2* m;
        for(int i=0;i<n;i++)arr.push_back(arr[i]);
        
        int sm=0;
        vector<int>pref(n,0);
        for(int i=0;i<n;i++){
            sm+=arr[i];
            pref[i]=sm;
        }
        
        int K=25;
        vector<vector<int>>dp(n,vector<int>(K,INT_MIN));
        for(int i=0;i<n;i++) dp[i][0]=pref[i];
        
        for(int k=1;k<K;k++){
            for(int i=0;i+(1<<(k-1))<n;i++){
             dp[i][k]= max(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
            }
        }
        int ans=INT_MIN;
        
        auto f=[&](int l, int r)->int{
            int val= r-l+1;
            int idx=l;
            int pos=0;
            int tans=INT_MIN;
            while(val>0){
                if(val&1){
                    tans=max(tans,dp[idx][pos]);
                    idx+=(1<<pos);
                }
                pos++;
                val>>=1;
            }
            return tans;
        };
        
        
        for(int i=0;i+m-1<n;i++){
            int l=i;
            int r=i+m-1;
            int mx= f(l,r);
            int lefsm= (i-1>=0)?pref[i-1]:0;
            int cur= mx-lefsm;
            ans=max(ans,cur);
        }
        return ans;
        
    }
};