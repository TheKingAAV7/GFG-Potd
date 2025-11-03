class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+2,INT_MAX);
        
    
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            if(i+1<n)
            dp[i]= min(dp[i], abs(arr[i+1] - arr[i]) + dp[i+1]);
            if(i+2<n)
            dp[i]= min(dp[i], abs(arr[i+2] - arr[i]) + dp[i+2]);
        }
        
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        return dp[0];
    }
};