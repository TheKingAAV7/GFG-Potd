//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
    private:
    void dfs(int node, vector<int>&vis,vector<vector<int>>&adj, stack<int>&st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0) dfs(it,vis, adj, st);
        }
        st.push(node);
        return;
    }
    private:
    void dfs3(int node, vector<vector<int>>&ad,vector<int>&vis1){
        vis1[node]=1;
        for(auto it:ad[node]){
            if(vis1[it]==0) dfs3(it, ad, vis1);
        }
        return ;
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        // time based sorting
        for(int i=0;i<n;i++){
            if(!vis[i])
            dfs(i,vis, adj,st);
        }
        //reverse edges
        vector<vector<int>>ad(n);
        for(int i=0;i<n;i++){
          for(auto it:adj[i]){
              ad[it].push_back(i);
          }  
        }
        // dfs
        vector<int>vis1(n,0);
        int cnt=0;
         while(!st.empty()){
             //cout<<st.top()<<" ";
             if(vis1[st.top()]==0){
                 cnt++;
                 dfs3(st.top(),ad,vis1);
             }
             st.pop();
         }
        // cout<<endl;
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends