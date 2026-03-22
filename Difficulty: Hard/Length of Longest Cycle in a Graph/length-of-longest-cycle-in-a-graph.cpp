class Solution {
  public:
    int longestCycle(int n, vector<vector<int>>& edges) {
        // code here
        int ans=-1;
        
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        
        vector<int>vis(n,-1);
        vector<int>tim(n,0);
        
        int curtime=0;
        
        function<void(int)>f=[&](int node)->void{
          vis[node]=2;
          tim[node]=curtime++;
        //   cout<<node<<" ";
          for(auto it:adj[node]){
              if(vis[it]==2){
                //   cout<<tim[it]<<" yes "<<tim[node]<<endl;
                  ans=max(ans,tim[node]-tim[it]+1);
              }
              if(vis[it]==-1){
                
                  f(it);
              }
          }
          vis[node]=1;
          return ;
        };
        for(int i=0;i<n;i++){
            if(vis[i]==-1) f(i);
            // cout<<endl;
        }
        return ans;
        
        
        
    }
};
