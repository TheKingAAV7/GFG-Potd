//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  vector<int>parent, rank;
  int find(int x){
      if(parent[x]==x) return x;
      return parent[x]=find(parent[x]);
  }
  
  bool unite(int x, int y){
      int parx=find(x);
      int pary=find(y);
      
      if(parx==pary){
          return false;
      }
      if(rank[parx]>rank[pary]){
          parent[pary]=parx;
      }
      else if(rank[parx]<rank[pary]){
          parent[parx]=pary;
      }
      else{
          parent[pary]=parx;
          rank[pary]++;
      }
      return true;
  }
  public:
    bool isCycle(int n, vector<vector<int>>& edges) {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
        for(auto it:edges){
        bool tmp=unite(it[0],it[1]);
        if(!tmp) return true;
        }
        return false;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends