class Solution {
  public:
  vector<int>rank;
  vector<int>par;

  int findpar(int node){
      if(par[node]==node) return node;
      return par[node]=findpar(par[node]);
  }
  
  bool uni(int x, int y){
      int parx=findpar(x);
      int pary=findpar(y);
      if(parx==pary) return true;
      if(rank[parx]>rank[pary]){
          par[pary]=parx;
      }
      else if(rank[pary]>rank[parx]){
          par[parx]=pary;
      }
      else{
          par[pary]=parx;
          rank[parx]++;
      }
      return false;
  }
    bool isCycle(int n, vector<vector<int>>& edges) {
        rank.resize(n,0);
        par.resize(n);
        
        iota(par.begin(),par.end(),0);
        for(auto it:edges){
            int x=it[0],y=it[1];
            if(uni(x,y)) return true;
        }
        return false;
        
        
        
    }
};