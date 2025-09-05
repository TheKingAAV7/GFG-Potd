class Solution {
  public:
    int perfectSum(vector<int>& arr, int tar) {
       int n=arr.size();
       vector<vector<int>>dp(n+1,vector<int>(tar+2,0));
       dp[n][0]=1;
       
       int ans=0;
       for(int i=n-1;i>=0;i--){
           for(int j=0;j<=tar;j++){
              if(arr[i]<=j){
                  dp[i][j]+=dp[i+1][j-arr[i]];
              }
              dp[i][j]+=dp[i+1][j];
             
              
           }
            
       }
     
        
    
       return dp[0][tar];
        
    }
};