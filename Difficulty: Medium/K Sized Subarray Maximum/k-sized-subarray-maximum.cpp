class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int K=25;
        vector<vector<int>>dp(n,vector<int>(K,-1));
        for(int i=0;i<n;i++) dp[i][0]=arr[i];
        for(int b=1;b<25;b++){
            for(int i=0;(i+(1<<b))<=n;i++){
                dp[i][b]= max(dp[i][b-1],dp[i+(1<<(b-1))][b-1]);
            }
        }
        int MAXN=n;
        int lg[MAXN+1];
        lg[1] = 0;
        for (int i = 2; i <= MAXN; i++)
            lg[i] = lg[i/2] + 1;
        vector<int>ans;
        
        auto f=[&](int L, int R)->int{
            int  i = lg[R - L + 1];
            int mx = max(dp[L][i], dp[R-(1<<i)+1][i]);
            return mx;
        };
        for(int i=0;i+k-1<n;i++){
            int tmp= f(i,i+k-1);
            ans.push_back(tmp);
        }
        return ans;
        
        
    }
};