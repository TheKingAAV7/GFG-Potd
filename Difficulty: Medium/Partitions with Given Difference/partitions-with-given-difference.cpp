class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        /*
        
        dp[diff]
        
       
        dp[i][diff]+= dp[i-1][diff+arr[i]];
        dp[i][diff]+=dp[i-1][diff-arr[i]];
        
        diff=[-sm, sm]
        */
        int n=arr.size();
        int sm= accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(3*sm,0));
        int shift=sm;
        dp[0][arr[0]+shift]++;
        dp[0][-arr[0]+shift]++;
        for(int i=1;i<n;i++){
            for(int cd= -sm; cd<=sm;cd++){
                dp[i][shift+cd]+=dp[i-1][cd+arr[i]+shift];
                dp[i][shift+cd]+=dp[i-1][cd-arr[i]+shift];
            }
        }
        return dp[n-1][diff+shift];
        
    }
};