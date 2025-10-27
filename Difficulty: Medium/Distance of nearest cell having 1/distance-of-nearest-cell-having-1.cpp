class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here 40000
       // 200*200*200
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        deque<array<int,3>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                ans[i][j]=0;
                q.push_back({i,j,0});
                }

            }
        }
        
        vector<int>row={1,-1,0,0};
        vector<int>col={0,0,-1,1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop_front();
            int x=cur[0];
            int y=cur[1];
            int cnt=cur[2];
            for(int i=0;i<4;i++){
                int nx=x+row[i];
                int ny=y+col[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and ans[nx][ny]>(cnt+1) 
                and grid[nx][ny]!=1){
                    ans[nx][ny]=cnt+1;
                    q.push_back({nx,ny,cnt+1});
                }
            }
        }
        // considering distance with reference to (-1,-1)
        /*
        
        so, push all the ones in queue and do bfs?
        (2,0,0) ( 3,1,0) (4,0,2) 
        n^3 
        
        */
        return ans;
    }
};