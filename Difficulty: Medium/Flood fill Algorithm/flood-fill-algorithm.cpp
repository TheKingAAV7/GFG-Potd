//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  vector<int>ro={-1,1,0,0};
  vector<int>col={0,0,-1,1};
  void dfs(int i, int j,int n, int m ,vector<vector<int>>&image,vector<vector<int>>&vis,int newColor,int colr){
      if(i<0 || j<0 || i>=n || j>=m) return ;
      vis[i][j]=1;
      image[i][j]=newColor;
      for(int id=0;id<4;id++){
          int nx=i+ro[id];
          int ny=j+col[id];
          if(nx>=0 and nx<n and ny>=0 and ny<m and vis[nx][ny]==0 and image[nx][ny]==colr){
              dfs(nx,ny,n,m,image,vis,newColor,colr);
          }
          
      }
      return;
  }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
      int n=image.size();
      int m=image[0].size();
      vector<vector<int>>vis(n,vector<int>(m,0));
      dfs(sr,sc,n,m,image,vis,newColor,image[sr][sc]);
      
      return image;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends