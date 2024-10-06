//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 void dfs(int m ,int n, vector<vector<char>>&g, int i, int j){
     if(i<0 || i> n-1 || j<0 || j>m-1 || g[i][j]=='0') return ;
     g[i][j]='0';
     
    
     dfs(m, n, g,i, j+1); // right
     dfs(m, n, g,i+1, j); // down
     dfs(m, n, g, i+1, j-1); //  dia l down
     dfs(m, n, g, i+1, j+1); //  dia r down1
     dfs(m,n, g, i-1, j); // up
     dfs(m, n, g,i, j-1 ); // left
     dfs(m, n, g, i-1,j-1);// dia l u
     dfs(m, n, g, i-1, j+1);// dia r u
     
     
     return; 
     
     
     
     
 }
 
  public:
    
    int numIslands(vector<vector<char>>& grid) {
            int ans=0;
            int n=grid.size();
            int m=grid[0].size();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1'){
                        dfs(m, n, grid, i, j);
                        ans++;
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
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends