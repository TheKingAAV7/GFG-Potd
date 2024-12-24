//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int l=0,h=mat.size()-1;
        while(l<=h){
            int mid=(l+(h-l)/2);
            if(x>=mat[mid][0] and x<=mat[mid].back() ){
                auto it=lower_bound(mat[mid].begin(),mat[mid].end(),x); 
                if(it!=mat[mid].end() and *it==x) return true;
                return false;
            }
            if(x>mat[mid].back()) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends