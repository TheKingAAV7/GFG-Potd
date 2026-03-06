class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        /*
        
        dp[i][x]+= dp[i-1][x-(1..m)]
        
        */
        vector<vector<int>>dp(n+1,vector<int>(x+2,0));
        
        for(int i=1;i<=min(x,m);i++) dp[0][i]=1;
        // for(int i=0;i<n;i++) dp[i][0]=1;
    
        
        for(int i=1;i<n;i++){
            for(int sm=1;sm<=x;sm++){
                for(int cur=1;cur<=m;cur++){
                    if(sm-cur>=0)
                    dp[i][sm]+=dp[i-1][sm-cur];
                }
            }
        }
        return dp[n-1][x];
        
        
    }
};