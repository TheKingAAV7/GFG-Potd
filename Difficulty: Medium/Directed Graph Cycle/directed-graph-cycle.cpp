class Solution {
  public:
  
    bool f(int node, vector<int>&vis, vector<int>adj[] ){
        vis[node]=1;
        bool ans=false;
        for(auto it:adj[node]){
            if(vis[it]==0) ans |=f(it, vis, adj);
            else if( vis[it]==1 ) return true;
        }
        
        vis[node]=2;
        
        return ans;
    }
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            
        }
        
        vector<int>vis(n,0);
        
        for(int i = 0; i < n; i++){
            if ( vis[i]==0 ){
                if(f(i,vis,adj)) return true;
            }
        }
        return false;
        
    }
};