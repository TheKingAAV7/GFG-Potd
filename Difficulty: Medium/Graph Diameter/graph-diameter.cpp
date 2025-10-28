class Solution {
  public:
    int diameter(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        auto bfs=[&](int node)-> pair<int,int>{
            queue<array<int,2>>q;
            vector<int>vis(n,-1);
            vis[node]=0;
            q.push({node,0});
            while(!q.empty()){
                auto cur=q.front();
                q.pop();
                int nod=cur[0];
                int dist=cur[1];
                for(auto it:adj[nod]){
                    if(vis[it]==-1){
                        vis[it]=dist+1;
                        q.push({it,dist+1});
                    }
                }
            }
           int mx=*max_element(vis.begin(),vis.end());
           for(int i=0;i<n;i++){
               if(vis[i]==mx) return {i,mx};
           }
           return {-1,-1};
        };
        
          auto tmp=bfs(0);
          int node=tmp.first;
          //cout<<node<<endl;
          
          tmp= bfs(node);
        return tmp.second;
        
    }
};
