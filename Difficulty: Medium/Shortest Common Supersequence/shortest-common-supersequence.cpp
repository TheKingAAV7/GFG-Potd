class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                dp[i][j] = max({dp[i][j],dp[i+1][j],dp[i][j+1]});
            }
        }
        return dp[0][0] + (n-dp[0][0] + (m-dp[0][0]));
    }
};