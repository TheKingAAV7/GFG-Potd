class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
  
        
        /*
        
        
        f(i,0)
        f(i+1,0)
        f(i+1,1)
        
        f(i+1,2)
        f(i+1)
        
        
        */
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            dp[i][0]= arr[i]+ dp[i+1][0];
            dp[i][0]= max(dp[i][0],arr[i]+dp[i+1][1]);
            
            // if(i==n-2) cout<<arr[i]^1 + max(dp[i+1][1],dp[i+1][2])<<endl;
            dp[i][1]=  (arr[i]^1) + max(dp[i+1][1],dp[i+1][2]);
            
            // if(i==n-2)
            // cout<<dp[i][1]<<endl;
            dp[i][2]=  arr[i]+ dp[i+1][2];
            
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        // }
        return max(dp[0][0],dp[0][1]);
    }
};