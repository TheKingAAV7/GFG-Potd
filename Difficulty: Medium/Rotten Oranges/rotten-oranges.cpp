class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        
        int n=mat.size();
        int m=mat[0].size();
        // cost,i,j
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        queue<array<int,3>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) fresh++;
                else if(mat[i][j]==2){
                vis[i][j]=1;
                q.push({0,i,j});
                }
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int cost=cur[0];
            int x=cur[1];
            int y=cur[2];
            if(mat[x][y]==1){
                fresh--;
                if(fresh==0) return cost;
            }
            for(int i=0;i<4;i++){
                int nx= x+dx[i];
                int ny= y+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and mat[nx][ny]==1 and vis[nx][ny]==0){
                    q.push({cost+1,nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return -1;
        
    }
};