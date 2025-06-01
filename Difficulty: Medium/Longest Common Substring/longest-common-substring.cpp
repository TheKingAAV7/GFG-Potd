class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n=s1.length(),m=s2.length();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                //take
                if(s1[i]==s2[j]){
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                    ans=max(ans,dp[i][j]);
                }
              
               
            }
        }
        return ans;
        
        
    }
};