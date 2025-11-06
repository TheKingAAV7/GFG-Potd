class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
       int n = jobs.size();
       sort(jobs.begin(),jobs.end());
       
       vector<int>dp(n+1,0);
       
       for(int i=n-1;i>=0;i--){
           dp[i]= max(dp[i],dp[i+1]);
           
           vector<int>tof={jobs[i][1],0,0};
           auto it= lower_bound(jobs.begin(),jobs.end(),tof);
           int idx= it-jobs.begin();
           dp[i]= max(dp[i],jobs[i][2]+dp[idx]);
       }
       return dp[0];
        
    }
};
