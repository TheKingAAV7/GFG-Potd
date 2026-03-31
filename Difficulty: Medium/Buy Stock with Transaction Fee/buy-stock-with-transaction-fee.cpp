class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        /*
        
        On a day options are
        
        0) skip -> dp[i][0]= max(dp[i+1][0],dp[i+1][1]) 
        1) buy -> dp[i][1]= -k-arr[i]+ max(dp[i+1][0],dp[i+1][2])
        2) sell-> dp[i][2]= arr[i]+dp[i+1][0],dp[i+1][1]        
        */
        
        int n=arr.size();
        int dp[n+1][2];
        
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(dp[i][1],dp[i+1][1]);
            dp[i][1]= max(dp[i][1],-k-arr[i]+dp[i+1][0]);
            dp[i][0]= max(dp[i][0],dp[i+1][0]);
            dp[i][0]= max(dp[i][0],arr[i]+dp[i][1]);
        }
        return dp[0][1];
        
    }
};