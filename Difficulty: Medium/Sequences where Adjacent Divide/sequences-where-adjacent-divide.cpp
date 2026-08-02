class Solution {
  public:

    
    
    int count(int n, int m) {
        // code here
        
        vector<vector<int>>dp(n+1,vector<int>(m+2,-1));
        auto f=[&](auto &&self, int i,int prev)->int{
            if(i>=n) return 1;
            int np= prev+1;
            if(dp[i][np]!=-1) return dp[i][np];
            int ans=0;
            if(prev==-1){
            for(int j=1;j<=m;j++){
                ans=(ans+self(self,i+1,j));
            }
            }
            else{
                for(int j=1;j<=m;j++){
                    if((prev%j==0) || (j%prev==0)) ans+=self(self,i+1,j);
                }
            }
            return dp[i][np]=ans;
        };
        return f(f,0,-1);
    }
};