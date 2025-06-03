class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n=s1.length();
        int m=s2.length();
        int o=s3.length();
        int dp[n+1][m+1][o+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=o;k++) dp[i][j][k]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int k=o-1;k>=0;k--){
                    if(s1[i]==s2[j] and s1[i]==s3[k]){
                        dp[i][j][k]=max(dp[i][j][k],1+dp[i+1][j+1][k+1]);
                    }
                    dp[i][j][k]=max({dp[i][j][k],dp[i+1][j][k],dp[i][j+1][k],dp[i][j][k+1]});
                }
            }
            
        }
        return dp[0][0][0];
    }
};
