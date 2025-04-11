//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
       
        vector<int>dist(n,INT_MAX);
        vector<int>vis(n,0);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(auto it1:adj[node]){
                auto it=it1.first;
                auto wt=it1.second;
                if(dist[node]+wt < dist[it]){
                    dist[it]=dist[node]+wt;
                    pq.push({dist[it],it});
                }
            }
        }
        return dist;
        
    }   
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends