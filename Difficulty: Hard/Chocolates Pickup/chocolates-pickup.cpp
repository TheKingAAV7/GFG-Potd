class Solution {
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        /*
        
        Assumptions:
        
        A node can't be reached with different times..
        
        there can be 9 combinations
        
        State: (i1,j1, i2,j2)
        
        how many states can be visited at max?
         i guess it's n only..
        
        */
        int dp[70][70][70];
        memset(dp,-1,sizeof(dp));
        vector<array<int,2>>dir={{1,-1},{1,0},{1,1}};
        function<int(int,int,int,int)>f=[&](int i1, int j1, int i2, int j2){
            if(i1<0 || i1>=n || i2<0 || i2>=n || j1<0 || j1>=m || j2<0 || j2>=m){
                return 0; // maybe INT_MIN
            }
            if(i1==n-1){
                array<int,2>a={i1,j1};
                array<int,2>b={i2,j2};
                if(a==b) return grid[i1][j1];
                return grid[i1][j1]+grid[i2][j2];
            }
            if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];
            int cur=0;
            array<int,2>a={i1,j1};
            array<int,2>b={i2,j2};
            if(a==b) cur=grid[i1][j1];
            else cur=grid[i1][j1]+grid[i2][j2];
            
            int ans=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int ni1=i1+dir[i][0];
                    int nj1=j1+dir[i][1];
                    int ni2=i2+dir[j][0];
                    int nj2=j2+dir[j][1];
                    ans=max(ans,cur+f(ni1,nj1,ni2,nj2));
                }
            }
            return dp[i1][j1][j2]=ans;
            
        };
        int ans=f(0,0,0,m-1);
        return ans;
        
    }
};