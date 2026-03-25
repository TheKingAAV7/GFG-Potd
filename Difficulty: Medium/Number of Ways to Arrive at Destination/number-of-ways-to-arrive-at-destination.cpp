class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<array<int,2>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // cost,node
        
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        pq.push({0,0});
        vector<int>dp(n,0);
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        dp[0]=1;
        while(!pq.empty()){
            auto cur= pq.top();pq.pop();
            int cost=cur[0];
            int node= cur[1];
            // cout<<"Node "<<node<<endl;
            for(auto it:adj[node]){
                int ncost= it[1]+cost;
                if(ncost<dist[it[0]]){
                    // cout<<it[0]<<" ";
                    dist[it[0]]=ncost;
                    dp[it[0]]=1;
                    pq.push({ncost,it[0]});
                }
                else if(ncost==dist[it[0]]){
                    // cout<<it[0]<<" ";
                    dp[it[0]]++;
                    pq.push({ncost,it[0]});
                }
            }
            // cout<<endl;
        }
        // for(int i:dp) cout<<i<<" ";
        // cout<<endl;
        return dp[n-1];
        
    }
};