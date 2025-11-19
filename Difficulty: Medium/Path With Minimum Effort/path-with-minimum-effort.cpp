class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        
        /*
        
        Simple, single, source, shortest, path..
        
        maintain the dp[i][j];
        
        dp[i][j] -> minimum cost
        
        priority queue will contain {cost, i,j, maxi,mini}
        Will it contain maxi and mini too?
        why NO? , Because there's no dependency right? Yes
        */
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        
        dp[0][0]=0;
        
        priority_queue<array<int,5>,vector<array<int,5>>,greater<array<int,5>>>pq;
        
    
        
        //priority_queue<array<int,5>,vector<array<int,5>>,greater<array<int,5>>>pq;
        
        pq.push({0,0,0,mat[0][0],mat[0][0]});
        
        
        vector<int>row={1,-1,0,0};
        vector<int>col={0,0,1,-1};
        
        while(!pq.empty()){
            auto cur= pq.top();
            pq.pop();
            int cst= cur[0];
            int i= cur[1];
            int j= cur[2];
            int mx= cur[3];
            int mn= cur[4];
            
          //  if(i==n-1 and j==m-1) return cst;
            
            if(dp[i][j]!=cst) continue; 
            
            for(int k=0;k<4;k++){
                int x= i+ row[k];
                int y= j+ col[k];
                
                if(x>=0 and x<n and y>=0 and y<m ){
                    
                    
                    int ncost=  max(cst,abs(mat[x][y]-mat[i][j]));
                    
                    if(ncost<dp[x][y]){
                        dp[x][y]=ncost;
                        pq.push({ncost,x,y,0,0});
                    }
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j:dp[i]) cout<<j<<" ";
        //     cout<<endl;
        // }
        
        
        return dp[n-1][m-1];
        
    }
};
