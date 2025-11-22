


vector<int>parent,rank1;


int findpar(int node){
    if(parent[node]==node) return node;
    return parent[node]= findpar(parent[node]);
}

void uni(int x, int y){
    int parx= findpar(x);
    int pary= findpar(y);
    if(parx==pary) return;
    
    if(rank1[parx]>rank1[pary]){
        parent[pary]= parx;
    }
    else if(rank1[pary]>rank1[parx]){
        parent[parx]= pary;
    }
    else{
        parent[pary]= parx;
        rank1[parx]++;
    }
    return;
}

int f(){
    int n=parent.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(parent[i]==i) cnt++;
    }
    return cnt;
}
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
     
     
     
     parent.resize(n,0);
     rank1.resize(n,0);
     iota(parent.begin(),parent.end(),0);
     
     for(auto it:edges){
         uni(it[0],it[1]);
     }
     
     cnt= f();
     
     
     
     
     
     return cnt-1;
        
        
        
    }
};

