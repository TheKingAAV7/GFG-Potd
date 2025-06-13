class Solution {
  public:
    bool isBipartite(int n, vector<vector<int>> &edges) {
      
      vector<vector<int>>adj(n);
      for(auto it:edges){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
      }
      vector<int>vis(n,-1);
      for(int i=0;i<n;i++){
          queue<int>q;
          if(vis[i]==-1){
              q.push(i);
              vis[i]=0;
              while(!q.empty()){
                  int node=q.front();q.pop();
                  for(auto it:adj[node]){
                      if(vis[it]==-1){
                          vis[it]=!vis[node];
                          q.push(it);
                      }
                      else if(vis[it]==vis[node]) return false;
                  }
              }
              
              
          }
      }
      return true;
      
        
    }
};