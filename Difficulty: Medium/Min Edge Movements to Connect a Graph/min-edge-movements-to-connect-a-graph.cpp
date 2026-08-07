class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        /*
        required edges= c - 1
        extra edges
        */
        
        vector<int>vis(n,0);
        
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        auto dfs=[&](auto &&self, int node, int &ncnt, int &ecnt) -> void{
            
            ncnt++;
            vis[node]=1;
            for(auto it:adj[node]){
                ecnt++;
                if(vis[it]==0){
                    self(self,it,ncnt,ecnt);
                }
            }
            return;
        };
        int extra=0;
        int compo=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int ncnt,ecnt;
                ncnt=ecnt=0;
                dfs(dfs,i,ncnt,ecnt);
                ecnt/=2;
                int rq= ncnt-1;
                int x= ecnt-rq;
                extra+=x;
                compo++;
            }
        }
        int req= compo - 1;
        if(extra >= req) return req;
        return -1;
    }
};