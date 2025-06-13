// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        
        vector<vector<vector<int>>>adj(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int wt=it[1];
                int nd=it[0];
                if(dist[nd]>(dis+wt)){
                    dist[nd]=dis+wt;
                    pq.push({dist[nd],nd});
                }
            }
        }
        
        return dist;
        
        
    }
};