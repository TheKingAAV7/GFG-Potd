class Solution {
  public:
    int shortCycle(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        int ans=INT_MAX;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        auto bfs=[&](int node,int &cur)->void{
          queue<array<int,3>>q;
          vector<int>vis(n,0);
          vis[node]=1;
          q.push({node,0,-1});
          while(!q.empty()){
              auto p=q.front();
              q.pop();
              int nod=p[0];
              int cnt=p[1];
              int par=p[2];
              for(auto it:adj[nod]){
                  if(it!=par){
                      if(vis[it]==1 and it==node) {
                          cur=cnt+1;
                          return;
                      }
                      else{
                          vis[it]=1;
                          q.push({it,cnt+1,nod});
                      }
                  }
              }
              
          }
          
        };
        for(int i=0;i<n;i++){
            int cur=INT_MAX;
            bfs(i,cur);
            //cout<<cur<<endl;
            if(cur!=INT_MAX){
                ans=min(ans,cur);
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};
