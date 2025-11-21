

class Solution {
  public:
    int minConnect(int n, vector<vector<int>>& edges) {
        
     /*
     
     Assumption: 
     If we have no. of edges atleast equal to  n-1 , then we can connect
     all the nodes
     To find minimum , 
     just find the no. of connected components c and the answer is c-1
     
     
     else we  cant
     */
     
     int sz= edges.size();
     if(sz<n-1) return -1;
     
     int cnt=0;
     vector<vector<int>>adj(n);
     for(auto it:edges){
         adj[it[0]].push_back(it[1]);
         adj[it[1]].push_back(it[0]);
     }
     
     vector<int>vis(n,0);
     
     function<void(int)>f=[&](int node)-> void{
       
       vis[node]=1;
       for(auto it: adj[node]){
           if(!vis[it]) f(it);
       }
       return;
         
     };
     for(int i=0;i<n;i++){
         if(!vis[i]){
             cnt++;
             f(i);
         }
     }
     
     return cnt-1;
        
        
        
    }
};

