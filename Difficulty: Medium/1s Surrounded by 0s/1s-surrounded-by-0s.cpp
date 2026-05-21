class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n= grid.size();
        int m= grid[0].size();
        queue<array<int,2>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){ 
                    grid[i][j]=0;
                    q.push({i,j});
                    }
                }
            }
        }
        
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int x= cur[0];
            int y= cur[1];
            for(int i=0;i<4;i++){
                int nx= x+dx[i];
                int ny= y+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cnt+=grid[i][j];
        }
        return cnt;
    }
};