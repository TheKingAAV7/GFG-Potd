class Solution {
  public:
    int derangeCount(int n) {
        // code here
        /*
        
        No element is at its correct position
        
        
        1 2 3 4 5
        */
        int MX= (1<<(n+1));
        vector<vector<int>>dp(n+1,vector<int>(MX,-1));
        function<int(int,int)>f=[&](int i ,int b)->int{
           if(i>n) return 1;
           if(dp[i][b]!=-1) return dp[i][b];
           int ans=0;
           for(int j=1;j<=n;j++){
               if(j!=i and ((b>>j)&1)==0){
                   ans+=f(i+1,b|(1<<j));
               }
           }
           return dp[i][b]=ans;
        };
        return f(1,0);
    }
};