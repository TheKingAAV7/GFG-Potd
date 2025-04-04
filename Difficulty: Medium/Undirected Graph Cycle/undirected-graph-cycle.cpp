//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  vector<int>rank,parent;
  
  bool uni(int a,int b){
      int parx=findpar(a);
      int pary=findpar(b);
      if(parx==pary){
          return true;
      }
      if(rank[parx]>rank[pary]){
          parent[pary]=parx;
      }
      else if(rank[pary]>rank[parx]){
          parent[parx]=pary;
      }
      else{
          parent[pary]=parx;
          rank[parx]++;
      }
      return false;
  }
  
  int findpar(int a){
      if(parent[a]==a) return a;
      return parent[a]=findpar(parent[a]);
  }
  public:
    bool isCycle(int n, vector<vector<int>>& edges) {
    parent.resize(n,0);
    rank.resize(n,0);
    iota(parent.begin(),parent.end(),0);
    for(auto it:edges){
        bool tmp=uni(it[0],it[1]);
        if(tmp) return true;
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