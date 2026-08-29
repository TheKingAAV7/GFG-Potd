class Solution {
  public:
    int countSubsequences(string& s, int n) {
        /*
        
        
        dp[i][x]= dp[i+1][(x*10+cur)%n]
        
        
        
                
        */
        
        int len= s.length();
        
        vector<vector<int>>dp(len,vector<int>(n,-1));
        int MOD=1e9+7;
        auto f=[&](auto &&self, int i, int mod)->int{
            if(i>=len) return mod==0;
            if(dp[i][mod]!=-1) return dp[i][mod];
            int ans=0;
            int a= self(self,i+1,mod);
            int cur=s[i]-'0';
            int b= self(self,i+1,(mod*10+cur)%n);
            return dp[i][mod]=(a+b)%MOD;
        };
        
        return f(f,0,0) - 1;
        
    }
};