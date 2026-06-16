class Solution {
  public:
    int maxProduct(int n) {
        // code here
        
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        auto f=[&](auto &&self, int n,int flag)->int{
            if(n<=1) return n;
            if(dp[n][flag]!=-1) return dp[n][flag];
            int ans=1;
            for(int j=1;j<=n;j++){
                if(j==n){
                    if(flag) ans=max(ans,j);
                }
                else
                ans=max(ans,j*self(self,n-j,1));       
            }
            return dp[n][flag]=ans;
        };
        
        
        return f(f,n,0);
    }
};