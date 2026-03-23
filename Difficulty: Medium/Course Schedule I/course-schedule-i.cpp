class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        // Code here
        /*
        
        
        */
        vector<vector<int>>adj(n);
        for(auto it:edges) adj[it[1]].push_back(it[0]);
        
        vector<int>vis(n,-1);
        
        function<bool(int)>f=[&](int node)->bool{
            vis[node]=2;
            bool ans=false;
            for(auto it:adj[node]){
                if(vis[it]==2) return true;
                else if(vis[it]==-1) ans|= f(it);
            }
            vis[node]=1;
            return ans;
        };
        
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                int tmp= f(i);
                if(tmp) return false;
            }
        }
        return true;
        
    }
};