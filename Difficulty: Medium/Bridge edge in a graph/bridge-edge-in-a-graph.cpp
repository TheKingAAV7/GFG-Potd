//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
   void f1(int node, vector<int>&vis,vector<int>&tim,vector<vector<int>>&adj,int parent){
      vis[node]=1;
      for(auto it:adj[node]){
         if(vis[it]==0){
            f1(it,vis,tim,adj,node);
            tim[node]=min(tim[node],tim[it]);
         }
         if(it!=parent){
            tim[node]=min(tim[node],tim[it]);
         }
      }
      return;
   }
  void dfs(int node,vector<int>&vis,vector<int>&tim,vector<vector<int>>&adj,int &timer,vector<int>&dis,int parent){
      
      vis[node]=1;
      tim[node]=dis[node]=timer;
      ++timer;
      for(auto it:adj[node] ){
          if(it==parent) continue;
          if(vis[it]==0){
             dfs(it,vis,tim,adj,timer,dis,node);
             tim[node]=min(tim[it],tim[node]);
          }
          else{
          tim[node]=min(tim[it],tim[node]);
          }
      }
      return;
  }
  public:
    bool isBridge(int n, vector<vector<int>> &edges, int c, int d) {
       vector<vector<int>>adj(n);
       for(auto it:edges){
               adj[it[0]].push_back(it[1]);
               adj[it[1]].push_back(it[0]);
       }
       vector<int>vis(n,0),dis(n,0);
       int timer=0;
       vector<int>tim(n,INT_MAX);
       for(int i=0;i<n;i++){
          if(vis[i]==0){
       dfs(i,vis,tim,adj,timer,dis,-1);
          }
       }
       
      //   for(auto it:tim) cout<<it<<" ";
      // cout<<endl;  
   
   
       fill(vis.begin(),vis.end(),0);
        for(int i=0;i<n;i++){
         if(vis[i]==0){
           
         f1(i,vis,tim,adj,-1);
      }
        } 
      
      // for(auto it:tim) cout<<it<<" ";
      // cout<<endl;      
       return tim[c]>tim[d] || tim[d]>tim[c];
       
        
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