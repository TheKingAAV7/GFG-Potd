//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int &d){
      if(node==d) return true;
      vis[node]=1;
      bool ans=false;
      for(auto it:adj[node] ){
          if(vis[it]==0){
              ans|=dfs(it,vis,adj,d);
          }
      }
      return ans;
  }
  public:
    bool isBridge(int n, vector<vector<int>> &edges, int c, int d) {
       vector<vector<int>>adj(n);
       for(auto it:edges){
           if(!((it[0]==c and it[1]==d) || (it[0]==d and it[1]==c)) ){
               adj[it[0]].push_back(it[1]);
               adj[it[1]].push_back(it[0]);
           }
       }
       vector<int>vis(n,0);
       bool f=dfs(c,vis,adj,d);
       if(f) return false;
       return true;
       
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends