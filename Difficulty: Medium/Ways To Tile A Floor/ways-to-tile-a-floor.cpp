class Solution {
  public:
    int numberOfWays(int n) {
       /*
       
      
           3->1
           2->1
           1->1 + 1
           0-> 2 +1
       let's say we are at ith position
       
       now , at this position we can 
       1) Either insert 2 pieces of 1*2
       2) Either insert 1 piece of 2*1
       
       1) dp[i] += dp[i+2]
       2) dp[i] +=dp[i+1]
       
       base case:
       
       dp[n]=1
       
       */
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(i+2<=n) dp[i]+= dp[i+2];
            dp[i]+=dp[i+1];
        }
        return dp[0];
    }
};
