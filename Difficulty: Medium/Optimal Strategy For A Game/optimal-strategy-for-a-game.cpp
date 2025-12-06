class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
    /*
    
    Let, dp[i][j][0] represents the maximum answer we can get if it's our
    turn
    and dp[i][j][1] represents the maximum answer we can get if it's not
    our turn 
    
    transition
    
    
    8 15 3
    
    (0,0) = 8
    (1,1) = 15
    (2,2) = 3
    
    len=1
    dp[0][1][0] = 15 
    
    
    
    
    
     5 3
   -> our turn 
    --> Take left or right
            dp[i][j][0] = max(arr[i]+dp[i+1][j][1],arr[j]+dp[i][j-1][1])
   -> not our turn 
            dp[i][j][1]= max(dp[i+1][j][0],dp[i][j-1][0])
    */
    
    int n=arr.size();
    int dp[n][n][2];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++){
        dp[i][i][0]=arr[i];
        dp[i][i][1]=0;
    }
    
    for(int len=1;len<n;len++){
        for(int i=0;i+len<n;i++){
            int j= i+len;
            dp[i][j][0] = max(arr[i]+dp[i+1][j][1],arr[j]+dp[i][j-1][1]);
            dp[i][j][1]= min(dp[i+1][j][0],dp[i][j-1][0]);
        }
    }
    
    return  dp[0][n-1][0];
    }
};