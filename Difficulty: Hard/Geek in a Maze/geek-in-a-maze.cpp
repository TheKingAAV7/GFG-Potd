class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        // code here
        /*
         ['.', '.', '.'], 
         ['.', '#', '.']
         ['.', '.', '.']
        */
        
        
        int n= mat.size();
        
        int m= mat[0].size();
        
        // i,j,u,d
        
        if(mat[r][c]=='#') return 0;
        int ans=1;
        queue<array<int,4>>q;
        q.push({r,c,u,d});
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        vis[r][c]=1;
        // 
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int row=cur[0];
            int col=cur[1];
            int ups=cur[2];
            int downs=cur[3];
            
            for(int j=0;j<4;j++){
                int nx=row+dx[j];
                int ny=col+dy[j];
                if(nx>=0 and nx<n and ny>=0 and ny<m and mat[nx][ny]=='.'){
                    if(vis[nx][ny]) continue;
                    int nu=ups-(j==1);
                    int nd=downs-(j==0);
                    if(j==0){
                    if(nd<0) continue;
                    ans++;
                    vis[nx][ny]=1;
                    q.push({nx,ny,nu,nd});
                    }
                    else if(j==1){
                        if(nu<0) continue;
                        ans++;
                        vis[nx][ny]=1;
                        q.push({nx,ny,nu,nd});
                    }
                    else{
                        vis[nx][ny]=1;
                        ans++;
                        q.push({nx,ny,nu,nd});
                    }
                }
            }
            
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<vis[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};