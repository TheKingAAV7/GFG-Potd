class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       
       vector<int>ro={-1,1,0,0};
       vector<int>col={0,0,1,-1};
       vector<vector<int>>vis(n,vector<int>(m,-1));
       
       function<bool(int, int,int)>dfs=[&](int i, int j,int cnt)->bool{
         bool ans=false;
         vis[i][j]=cnt;
         for(int k=0;k<4;k++){
             int nx=i+ro[k];
             int ny=j+col[k];
             if(nx<0 || ny<0 || nx>=n || ny>=m) {
                 ans=true;
                 continue;
             }
             
             if(grid[nx][ny]=='O' and vis[nx][ny]==-1){
                 ans|=dfs(nx,ny,cnt);
             }
         }
         return ans;
       };
       
       int tim=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j]=='O' and vis[i][j]==-1){
                     bool tmp=dfs(i,j,tim);
                   //  cout<<tim<<" "<<i<<" "<<j<<endl;
                    //  for(int i1=0;i1<n;i1++){
                    //      for(int j1=0;j1<m;j1++) cout<<vis[i1][j1]<<" ";
                    //      cout<<endl;
                    //  }
                     
                     if(!tmp){
                         for(int i1=0;i1<n;i1++){
                             for(int j1=0;j1<m;j1++){
                                 if(grid[i1][j1]=='O' and vis[i1][j1]==tim) 
                                 grid[i1][j1]='X';
                             }
                         }
                     }
                     tim+=1;
                 }
             }
         }
         
         return ;
       
        
    }
};