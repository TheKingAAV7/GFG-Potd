class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        // 1 3 4 5
        // 2 3  5
        
        /*
        
        if(i>=n and j>=m) return 0;
        dp[i][j]= (a[i]*b[j]) + dp[i+1][j+1];
        
        dp[i][j]= dp[i+1][j];
        */
        
        int n= a.size();
        int m= b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
        for(int i=0;i<=n;i++) dp[i][m]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(dp[i+1][j+1]!=INT_MIN)
                dp[i][j]= max(dp[i][j], a[i]*b[j] + dp[i+1][j+1]);
                if(dp[i+1][j]!=INT_MIN)
                dp[i][j]= max(dp[i][j], dp[i+1][j]);
            }
        }
        int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[0][0];
        
        
    }
};
