//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  vector<int>row={-1,1,0,0,1,-1,-1,1};
  vector<int>col={0,0,-1,1,1,-1,1,-1};
  void dfs(int i, int j,vector<vector<char>>&grid,vector<vector<int>>&vis,int n, int m){
      if(i<0 || i>=n || j<0 || j>=m || vis[i][j]) return;
      vis[i][j]=1;
      for(int ix=0;ix<8;ix++){
          int nx= i+row[ix];
          int ny= j+col[ix];
          if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and grid[nx][ny]=='L'){
              dfs(nx,ny,grid,vis,n,m);
          }
      }
      return;
      
  }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='L'){
                ans++;
                dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends