class Solution {
  private:
  int f(int node,vector<vector<int>>&adj,vector<int>&vis,int dest,vector<int>&dp){
      if(dp[node]!=-1) return dp[node];
      if(node==dest) return 1;
      dp[node]=0;
      for(auto it:adj[node]){
          dp[node]+=f(it,adj,vis,dest,dp);
      }
      return dp[node];
  }
  public:
    int countPaths(vector<vector<int>>& edges, int n, int src, int dest) {
       vector<vector<int>>adj(n);
       for(auto it:edges){
           adj[it[0]].push_back(it[1]);
       }
       vector<int>dp(n,-1);
       
       vector<int>vis(n,0);
       int ans=f(src,adj,vis,dest,dp);
       
       return ans;
        
    }
};