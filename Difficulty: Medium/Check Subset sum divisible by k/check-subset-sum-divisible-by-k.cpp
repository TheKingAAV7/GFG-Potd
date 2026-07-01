class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        int n= arr.size();
        
        /*
        
        dp[i][k][0] |= dp[i+1][cur]
        dp[i][k][0] |= dp[i+1][(cur+arr[i])%K]   
        
        dp[i][k] |= dp[i+1][cur]
        dp[i][k] |= dp[i+1][(cur+arr[i])%K] 
        
        if(k==0) 
        */
        
        
        
        int dp[n+1][k][2];
        fill(&dp[0][0][0], &dp[0][0][0]+((n+1)*k*2),0);
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k,vector<int>(2,0)));
        
        
        dp[n][0][1]=1;
        for(int i=n-1;i>=0;i--){
            for(int cur=0;cur<k;cur++){
                for(int took=0;took<2;took++){
                    dp[i][cur][took]|=(dp[i+1][cur][took] | (dp[i+1][(cur+arr[i])%k][1]));
                }
            }
        }
        
        return dp[0][0][0];
        
        
    }
};