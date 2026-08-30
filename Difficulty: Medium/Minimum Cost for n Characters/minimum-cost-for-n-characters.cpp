class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=i;
        
        for(int j=2;j<=n;j++){
            int a= dp[j-1]+i;
            int b= (j%2==0)?(dp[j/2]+c): dp[(j+1)/2]+c+d;
            dp[j]= min(a,b);
        }
        return dp[n];
        
        
    }
};
