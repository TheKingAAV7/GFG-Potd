class Solution {
  public:
    int shortestPath(int n, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<array<int,2>>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // cost  node
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>dq;
       
        vector<int>dist(n,INT_MAX);
        dq.push({0,src});
        dist[src]=0;
        while(!dq.empty()){
            auto cur= dq.top();
            dq.pop();
            int cst= cur[0];
            int nod= cur[1];
            if(cst>dist[nod]) continue;
            if(nod==dest){
                return cst;
            }
            for(auto it:adj[nod]){
                
                   int ndist= cst+it[1];
                   if(ndist<dist[it[0]]){
                       dist[it[0]]=ndist;
                       dq.push({ndist,it[0]});
                   }
            }            
        }
        
        return -1;
        
        
    }
};