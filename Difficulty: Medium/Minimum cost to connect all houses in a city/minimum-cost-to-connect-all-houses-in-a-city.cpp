class Solution {
  public:
    vector<int>parent;
    vector<int>rank;
    
    int findpar(int x){
        if(parent[x]==x) return x;
        return parent[x]=findpar(parent[x]);
    }
    
    bool uni(int u, int v){
        int paru=findpar(u);
        int parv=findpar(v);
        if(paru==parv) return false;
        
        if(rank[paru]>rank[parv]){
            parent[parv]=paru;
        }
        else if(rank[parv]>rank[paru]){
            parent[paru]=parv;
        }
        else{
            parent[parv]=paru;
            rank[paru]++;
        }
        
        return true;
    }
    int minCost(vector<vector<int>>& houses) {
        // code here
        
        map<array<int,2>,int>mp;
        int n=houses.size();

        int nod=0;
        for(auto it:houses){
            mp[{it[0],it[1]}]=nod++;
        }
        // cost,
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=houses[i][0];
                int y1=houses[i][1];
                int x2=houses[j][0];
                int y2=houses[j][1];
                int dist= abs(x1-x2) + abs(y1-y2);
                pq.push({dist,mp[{x1,y1}],mp[{x2,y2}]});
            }
        }
        parent.resize(n,0);
        rank.resize(n,0);
        iota(parent.begin(),parent.end(),0);
        int ans=0;
        while(!pq.empty()){
            auto cur=pq.top();pq.pop();
            int cost= cur[0];
            int nd1= cur[1];
            int nd2= cur[2];
            if(uni(nd1,nd2)){
                ans+=cost;
            }
        }
        return ans;
        
        
    }
};