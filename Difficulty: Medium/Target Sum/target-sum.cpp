class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n=arr.size();
        int sm= accumulate(arr.begin(),arr.end(),0);
        int csm=4*sm; // min(target,sm)
        sm=2*sm;
       
        vector<vector<int>>dp(n,vector<int>(csm+1,0));
        if(target> csm || target<(-csm)) return 0;
        
        dp[n-1][-arr.back()+sm]++;
        dp[n-1][arr.back()+sm]++;
        for(int i=n-2;i>=0;i--){
            for(int x=(-sm);x<=sm;x++){
                dp[i][x+sm]+= dp[i+1][x-arr[i]+sm];
                dp[i][x+sm]+= dp[i+1][x+arr[i]+sm];
            }
        }
        return dp[0][target+sm];
    }
};