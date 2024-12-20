//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int>row={0,1,0,-1};
        vector<int>col={1,0,-1,0};
        int n=mat.size(),m=mat[0].size();
        int pos=0;
        vector<int>ans;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int i=0,j=0;
        while(true){
            if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 ) break;
            
            while(i<n and j>=0 and i>=0 and j<m and vis[i][j]==0){
                ans.push_back(mat[i][j]);
                vis[i][j]=1;
                i+=row[pos];
                j+=col[pos];
            }
            i-=row[pos];
            j-=col[pos];
           // cout<<i<<" "<<j<<endl;
            pos=(pos+1)%4;
            i+=row[pos];
            j+=col[pos];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends