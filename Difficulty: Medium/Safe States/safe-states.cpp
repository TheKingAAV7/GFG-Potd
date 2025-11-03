class Solution {
  public:
  
    void dfs(int node, vector<int>&dp,vector<vector<int>>&adj){
        
        dp[node]=2;
        bool safe=1;
        for(auto it:adj[node]){
            if(dp[it]==0) dfs(it,dp,adj);
            if(dp[it]==2 || dp[it]==-1){
                safe=0;
                break;
            }
        }
        if(safe) dp[node]=1;
        else dp[node]=-1;
        
        return;
        
        
        
    }
    vector<int> safeNodes(int n, vector<vector<int>>& edges) {
        // Code here
        /*
        
        
        1) ALl terminal nodes will be safe
        2) If a component contains cycle.., No node  will be be saafe (except termininal)
          Wait this, fails..
        3)  Let's run a dfs from each node,  let''s assign some value to dp[node] and
        continue dfs if we get the same node, in the path..
        
        To check safeness of a node, check safeness of others..
        
        
        */
        vector<int>ans;
        vector<vector<int>>adj(n);
        vector<int>dp(n,0);
        for(auto it:edges){
         adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0;i<n;i++){
            if(dp[i]==0){
                dfs(i,dp,adj);
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]==1) ans.push_back(i);
        }
        return ans;
    }
};