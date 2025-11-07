class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        /*
        dp[i][j][x] -> no. of ways to get exactly x coins
        
        dp[i][j][x] = dp[i-1][j][x-arr[i][j]]
        */
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,0)));
        if(mat[0][0]<=k)
        dp[0][0][mat[0][0]]=1;
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) dp[i][j][0]=1;
        // }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) continue;
                int cur= mat[i][j];
                for(int x=0;x<=k;x++){
                    
                    if(i-1>=0 and (x-cur>=0))
                    dp[i][j][x]+= dp[i-1][j][x-cur];
                    if(j-1>=0 and (x-cur>=0) )
                    dp[i][j][x]+= dp[i][j-1][x-cur];
                }
            }
        }
        return dp[n-1][m-1][k];
    }
};