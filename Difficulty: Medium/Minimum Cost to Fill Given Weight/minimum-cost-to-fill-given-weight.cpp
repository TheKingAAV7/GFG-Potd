class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        /*
        
        
        
        dp[i][w]= dp[i-1][w]
        dp[i][w]= dp[i-1][w-i-1]
        dp[i][w]= dp[i][w-i-1]
        */
        
        int n= cost.size();
        vector<vector<int>>dp(n+1,vector<int>(w+1,INT_MAX));
        for(int i=0;i<n;i++) dp[i][0]=0;
        int cnt=1;
        if(cost[0]!=-1){
        for(int j=1;j<=w;j++){
        dp[0][j]=j*cost[0];
        // cout<<j<<"  -> "<<dp[0][j]<<endl;
        }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=w;j++){
                dp[i][j]= min(dp[i][j],dp[i-1][j]);
                if(cost[i]==-1) continue;
                if(j-1-i>=0){
                int prev= dp[i-1][j-i-1];
                if(prev!=INT_MAX)
                dp[i][j]= min(dp[i][j],cost[i]+dp[i-1][j-i-1]);
                if(dp[i][j-i-1]!=INT_MAX)
                dp[i][j]= min(dp[i][j],cost[i]+dp[i][j-i-1]);
                
                }
            }
        }
        
        return (dp[n-1][w] == INT_MAX ? -1 : dp[n-1][w]);
    }
};
