class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int n=  mat.size();
        int m= mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mx=0;
        for(int j=0;j<m;j++) {
        dp[0][j]= mat[0][j];
        mx=max(mx,mat[0][j]);
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    if(j==k) continue;
                    dp[i][j]= max(dp[i][j],mat[i][j]+dp[i-1][k]);
                    mx=max(mx,dp[i][j]);
                }
            }
        }
        return mx;
        
        
        
        
    }
};