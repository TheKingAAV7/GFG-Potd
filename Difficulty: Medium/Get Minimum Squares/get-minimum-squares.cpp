class Solution {
  public:
    int minSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        
        vector<int>ps;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            ps.push_back(i*i);
        }
        for(int i=1;i<=n;i++){
            for(int j:ps){
                if(i>=j){
                    dp[i]=  min(dp[i], 1 + dp[i-j]);
                }
            }
        }
        return dp[n];
        
    }
};