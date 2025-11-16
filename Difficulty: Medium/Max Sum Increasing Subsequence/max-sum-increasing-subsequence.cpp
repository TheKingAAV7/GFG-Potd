class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        vector<int>dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            // don't select
          //  dp[i]=max({dp[i],dp[i+1],arr[i]});
          dp[i]=arr[i];
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    dp[i]=max(dp[i],arr[i]+dp[j]);
                }
            }
        }
        int mx=0;
        for(int i:dp) mx=max(mx,i);
        
        return mx;
        
    }
};