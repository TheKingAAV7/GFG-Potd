//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private: 
void f(int i, int j, int &n , set<vector<int>>&st,vector<vector<int>>&vis,vector<int>&tmp,int noq){
   
    if(noq==n){
      
        st.insert(tmp);
        return ;
    }
    if(i<0 || i>=n || j<0 || j>=n || vis[i][j]){
        return ;
    }
    if(vis[i][j]==0){
        
        vector<int> prev_col(n, 0), prev_main_diag(n, 0), prev_anti_diag(n, 0);
         for (int row = 0; row < n; ++row) {
            prev_col[row] = vis[row][j];
            if (i + row < n && j + row < n)
                prev_main_diag[row] = vis[i + row][j + row];
            if (i + row < n && j - row >= 0)
                prev_anti_diag[row] = vis[i + row][j - row];
        }
        for(int ind=i;ind<n;ind++){
            vis[ind][j]=1;
        }
        for (int ind = 0; ind < n - i; ++ind) {
            if (j + ind < n) vis[i + ind][j + ind] = 1;
            if (j - ind >= 0) vis[i + ind][j - ind] = 1;
        }
        
       
        
        tmp.push_back(j+1);
        for(int col=0;col<n;col++){        
            f(i+1,col,n,st,vis,tmp,noq+1);
            
        }
       // cout<<endl;
        
        
            tmp.pop_back();
            
                for (int row = 0; row < n; ++row) {
            vis[row][j] = prev_col[row];
            if (i + row < n && j + row < n)
                vis[i + row][j + row] = prev_main_diag[row];
            if (i + row < n && j - row >= 0)
                vis[i + row][j - row] = prev_anti_diag[row];
        }

        
        
    }
    return ;
}


public:
    vector<vector<int>> nQueen(int n) {
        
        set<vector<int>>st;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<int>tmp;
        int noq=0;
        for(int col=0;col<n;col++){
          
        f(0,col,n,st,vis,tmp,noq);
        }
        vector<vector<int>>ans(st.begin(),st.end());
        
        
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends