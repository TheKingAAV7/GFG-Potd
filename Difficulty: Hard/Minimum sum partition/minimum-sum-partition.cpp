class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        // 1 5 6 11 .
        /*
        
        n*sm<=1e5
        
        
        dp[i][sm]-> if this sm is achievable or not..
        
        dp[x][0]-> true;
        
        Transition
        
        
        
        */
        
        int n= arr.size();
        int sm=accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(sm+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int x=1;x<=sm;x++){
                dp[i][x]|=dp[i-1][x];
                if(x-arr[i]>=0)
                dp[i][x]|=dp[i-1][x-arr[i]];
            }
        }
        int ans=INT_MAX;
        for(int x=0;x<=sm;x++){
            int cur= x;
            int rem= sm-x;
            
            if(dp[n-1][cur] and dp[n-1][rem]){
                ans= min(ans,abs(rem-cur));
            }
        }
        return ans;
            
            
    }
};
