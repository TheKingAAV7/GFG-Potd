class Solution {
  public:
    int countWays(int n, int m) {
        
        
        
        int mod=1e9+7;
        if(n==m) return 2;
        if(n<=m) return 1;
        /*
        
        at the current row..
        
        
        insert horizontal one
        or fill with many vertical ones
        
        */
        
        vector<int>dp(n+1,0);
        
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--){
            // insert a horizontal one
            if(i+1<=n)
            dp[i]= (dp[i]+dp[i+1])%mod;
            
            // many vertical ones
            if(i+m<=n)
            dp[i]= (dp[i]+dp[i+m])%mod;
        }
        
        
        
        return dp[0];
    }
};