//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  bool f(int i, int j, int k, int n,int m,vector<vector<char>>&mat,string &word,vector<vector<int>>&vis){
      if(k>=word.length()) return true;
      if(i>=n || i<0 || j>=m || j<0 || vis[i][j]) return false;
      bool ans=false;
      if(mat[i][j]==word[k]){
          vis[i][j]=1;
          ans|=f(i-1,j,k+1,n,m,mat,word,vis);
          ans|=f(i+1,j,k+1,n,m,mat,word,vis);
          ans|=f(i,j+1,k+1,n,m,mat,word,vis);
          ans|=f(i,j-1,k+1,n,m,mat,word,vis);
          vis[i][j]=0;
      }
      return ans;
  }
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
      
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(mat[i][j]==word[0]){
                  vector<vector<int>>vis(n,vector<int>(m,0));
                ans |=f(i,j,0,n,m,mat,word,vis);
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
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends