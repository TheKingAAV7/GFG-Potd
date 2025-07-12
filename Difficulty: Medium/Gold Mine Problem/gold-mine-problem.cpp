class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        // dp[i][j] [0,1,2]  0>rig,1>lef,2>rig maxi
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[i][m-1]=mat[i][m-1];
        }
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                int a= 0, b=0, c=0;
                if(i-1>=0){
                    a=dp[i-1][j+1];
                }
                if(i+1<n){
                    b=dp[i+1][j+1];
                }
                c=dp[i][j+1];
                dp[i][j]=max({a,b,c})+mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
        
    }
};