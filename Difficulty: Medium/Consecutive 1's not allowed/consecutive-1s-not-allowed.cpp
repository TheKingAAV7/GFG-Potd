class Solution {
  public:
    int countStrings(int n) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        function<int(int,int)>f=[&](int i,int prev){
            if(i>=n) return 1;
            int nprev= prev+1;
            if(dp[i][nprev]!=-1) return dp[i][nprev];
            int ans=0;
            if(prev==-1){
                ans+=f(i+1,0);
                ans+=f(i+1,1);
            }
            else if(prev==0){
                ans+=f(i+1,0);
                ans+=f(i+1,1);
            }
            else ans+=f(i+1,0);
            
            return dp[i][nprev]=ans;
        };
        return f(0,-1);
    }
};