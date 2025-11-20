class Solution {
  public:
    int shortestPath(int n, int a, int b, vector<vector<int>> &edges) {
        // code here
        
        
        /*
        
        
        Simple Dijkstra's algorithm 
        
        
        the state will be represented by dp[i][k] k will be 0 or 1
        k defines if we have used the curved edge or not
        */
        
        vector<vector<int>>dp(n,vector<int>(2,INT_MAX));
        vector<vector<array<int,3>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2],it[3]});
            adj[it[1]].push_back({it[0],it[2],it[3]});
        }
        
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        
        dp[a][0]=0;  // cost, node, k
        dp[a][1]=0;
        pq.push({0,a,0});
        pq.push({0,a,1});
        
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cst= cur[0];
            int node= cur[1];
            int used= cur[2];
            
            if(node==b) return cst;
            
            if(dp[node][used]!=cst) continue;
            
            for(auto it:adj[node]){
                int nod= it[0];
                int w1= it[1];
                int w2= it[2];
                // we can either use curved or normal
                
                // normal
                
                int cost= cst + w1;
                if(dp[nod][used]>cost){
                    dp[nod][used]=cost;
                    pq.push({cost,nod,used});
                }
                
                if(!used){
                    int cost1= cst + w2;
                    if(dp[nod][1] > cost1){
                        dp[nod][1]=cost1;
                        pq.push({cost1,nod,1});
                    }
                }
                
            }
        }
        
        return -1;
        
    }
};