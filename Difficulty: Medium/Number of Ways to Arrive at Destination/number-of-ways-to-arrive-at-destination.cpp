class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<array<int,2>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>dp(n,0);
        vector<int>dist(n,INT_MAX);
        // cost, node
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        
        pq.push({0,0});
        dp[0]=1;
        dist[0]=0;
        
        while(!pq.empty()){
            auto cur= pq.top();
            pq.pop();
            int cst= cur[0];
            int nd= cur[1];
           if(cst>dist[nd]) continue;
            
            
            for(auto it:adj[nd]){
                int node= it[0];
                int wt= it[1];
                int ndist= cst + wt;
                if(ndist<dist[node]){
                    dist[node]= ndist;
                    dp[node]=dp[nd];
                    pq.push({ndist,node});
                }
                else if(ndist==dist[node]){
                    dp[node]+= dp[nd];
                }
            }
        }
        
        // for(int i:dist) cout<<i<<" ";
        // cout<<endl;
        
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        
        return  dp[n-1];
    }
};