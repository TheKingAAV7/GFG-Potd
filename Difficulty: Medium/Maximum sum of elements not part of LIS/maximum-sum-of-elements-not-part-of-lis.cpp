class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        /*
          3 2 5 7
        */
        int n=arr.size();
        vector<pair<int,int>>dp(n);
        int total=accumulate(arr.begin(),arr.end(),0);
        for(int i=0;i<n;i++){
            dp[i]={1,arr[i]};
        }
      
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                   int len=dp[j].first+1;
                   int sm= dp[j].second+arr[i];
                   if(len>dp[i].first){
                       dp[i].first=len;
                       dp[i].second=sm;
                   }
                   else if(len==dp[i].first){
                       if(sm<dp[i].second) dp[i].second=sm;
                   }
                }
            }
        }
        int maxi=1;
        for(int i=0;i<n;i++) maxi=max(dp[i].first,maxi);
        
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(dp[i].first==maxi) mini=min(mini,dp[i].second);
        }
        return total-mini;
        
        
        
    }
};