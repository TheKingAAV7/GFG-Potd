class Solution {
  public:
  bool dfs(int node, vector<vector<int>>&adj,vector<int>&dp,vector<int>&vis){
    
    dp[node]=1;
    vis[node]=1;
    bool ans=false;
    for(auto it:adj[node]){
        if(!vis[it]){
            ans|= dfs(it,adj,dp,vis);
        }
        else if(dp[it]==1) ans=true;
    }
    dp[node]=2;
    return ans;
}
    vector<int> findOrder(int n, vector<vector<int>> &edges) {
        // code here
        /*
        
        edge will be from x-> y;
        we have to find cycle as well.. if there's one return {}
        
        else just topo right?
        
        How do we detect cycle?
        
        */
        
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>dp(n,0);
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,dp,vis)) return {};
            }
        }
        
        vector<int>ans;
        fill(vis.begin(),vis.end(),0);
        function<void(int)>f=[&](int node)->void{
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]){
                    f(it);
                }
            }
            ans.push_back(node);
        };
        
        for(int i=0;i<n;i++){
            if(!vis[i]) f(i);
        }
        
        // for(int i:ans) cout<<i<<" ";
        // cout<<endl;
        //reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
    }
};