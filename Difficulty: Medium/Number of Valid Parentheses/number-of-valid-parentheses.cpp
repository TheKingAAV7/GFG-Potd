class Solution {
  public:
  /*
  
    2->1
    0->1
  
    0->1
    1->1
    
    0 1 2 3 
    
    
  */
  
    int findWays(int n) {
        // code here
        if(n%2==1) return 0;
        n/=2;
        function<int(int,int)>NCR=[&](int n, int r)->int{
            vector<vector<int>>dp(n+1,vector<int>(r+1,0));
            if(r==0) return 1;
            for(int i=0;i<=n;i++) dp[i][0]=1;
            for(int i=1;i<=r;i++) dp[0][i]=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=r;j++){
                    dp[i][j]= dp[i-1][j] + dp[i-1][j-1];
                }
            }
            return dp[n][r];
        };
        int ncr= NCR(2*n,n);
        
      //  cout<<ncr<<endl;
        int ans=  (ncr)/(n+1);
        return ans;
        
    }
};