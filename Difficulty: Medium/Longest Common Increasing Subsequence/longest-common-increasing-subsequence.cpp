class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        
        int n=a.size();
        int m=b.size();
        vector<int>dp(m,0);
        
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=0;j<m;j++){
                if(a[i]==b[j]){
                    dp[j]=max(dp[j],1+cur);
                }
                else if(b[j]<a[i]){
                    cur= max(cur,dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
        
    }
};