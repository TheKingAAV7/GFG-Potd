class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        int n=arr.size();
        int mx= *max_element(arr.begin(),arr.end());
        vector<int>dp(mx+1,0);
        int ans=1;
        dp[arr[0]]=1;
        for(int i=1;i<n;i++){
            int x= arr[i];
            if(x-1>=0){
                dp[x]=max(dp[x],1+dp[x-1]);
            }
            if(x+1<=mx) dp[x]=max(dp[x],1+dp[x+1]);
            ans=max(dp[x],ans);
        }
        return ans;
    }
};