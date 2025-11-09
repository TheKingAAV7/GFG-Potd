class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        // code here
        /*
        
        Take profits quiclky?
        
        
        3   5  99 99  100
         
        */
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        function<int(int,int)>f = [&](int i, int buy){
            if(i>=n) return 0;
            if(dp[i][buy]!=-1) return dp[i][buy];
            
            int ans=0;
            
            if(buy){
                // continue; don't buy now..
                ans = max(ans,f(i+1,buy));
                
                // buy now
                
                ans= max(ans, -arr[i] + f(i+1,!buy));
                return dp[i][buy]=ans;
            }
            
            // don't sell now..
            ans= max(ans,f(i+1,buy));
            // sell now
            ans= max(ans,arr[i] + f(i+2,!buy));
            return dp[i][buy]=ans;
        };
        return f(0,1);
    }
};