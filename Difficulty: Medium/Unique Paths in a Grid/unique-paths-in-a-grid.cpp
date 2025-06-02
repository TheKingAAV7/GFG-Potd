class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
       int n=grid.size();
       int m=grid[0].size();
       if(grid.back().back()==1) return 0;

       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       dp[n-1][m-1]=1;
       for(int i=n-1;i>=0;i--){
           for(int j=m-1;j>=0;j--){
               
               if(grid[i][j]==0){
               if(i+1<n)
               dp[i][j]+=dp[i+1][j];
               if(j+1<m)
               dp[i][j]+=dp[i][j+1];
               }
               
           }
       }
       return dp[0][0];
    }
};