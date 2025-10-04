class Solution {
  public:
    vector<int>ro={1,-1,0,0};
    vector<int>col={0,0,1,-1};
    string dir="DURL";
    
    void f(int i, int j, int n, vector<vector<int>>vis,string &tmp,vector<string>&ans,
    vector<vector<int>>&grid){
        //if(i<0 || i>=n || j<0 || j>=n) return ;
        if(i==n-1 and j==n-1){
            ans.push_back(tmp);
            return ;
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+ro[k];
            int ny=j+col[k];
            char d=dir[k];
            if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==1 and vis[nx][ny]==0){
                tmp.push_back(d);
                f(nx,ny,n,vis,tmp,ans,grid);
                tmp.pop_back();
            }
        }
        return;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& grid) {
        // code here
        vector<string>ans;
        string tmp="";
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        f(0,0,n,vis,tmp,ans,grid);
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};