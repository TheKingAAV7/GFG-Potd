class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        
        int n= h.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        
        for(int i=n-1;i>=0;i--){
         dp[i][0]= max(dp[i+1][1],dp[i][0]);
         dp[i][0]= max(dp[i][0],h[i]+dp[i+1][1]);
         dp[i][0]= max(dp[i][0],l[i]+dp[i+1][1]);
         
         
         dp[i][1]= max(dp[i+1][0],dp[i][1]);
         dp[i][1]= max(dp[i][1],l[i]+dp[i+1][1]);
         
        }    
        return max(dp[0][0],dp[0][1]);
    }
};