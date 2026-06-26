class Solution {
  public:
    int countWays(string &s1, string &s2) {
        // code here
        int n= s1.length();
        int m= s2.length();
        int mod= 1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        auto f=[&](auto &&self, int i, int j)->int{
            if(j>=m) return 1;
            if(i>=n) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int ans=0;
            int skip= self(self, i+1,j);
            int nskip=0;
            if(s1[i]==s2[j]){
                nskip= self(self,i+1,j+1);
            }
            
            return dp[i][j]=(skip+nskip)%mod;
        };
        
        return f(f,0,0);
        
    }
};
