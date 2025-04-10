//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  vector<int>rank,parent;
  
  int findpar(int u){
      if(parent[u]==u) return u;
      return parent[u]=findpar(parent[u]);
  }
  bool uni(int u,int v){
      int upar=findpar(u);
      int vpar=findpar(v);
      if(upar==vpar) return false;
      if(rank[upar]>rank[vpar]){
          parent[vpar]=upar;
      }
      else if(rank[vpar]>rank[upar]){
          parent[upar]=vpar;
      }
      else{
          parent[vpar]=upar;
          rank[upar]++;
      }
      return true;
  }
  public:
    int minCost(vector<vector<int>>& houses) {
      int n=houses.size();
      map<string,int>mp;
      set<pair<int,pair<int,int>>>st;
      
      
      int cnt=0;
      for(int i=0;i<n;i++){
          string tmp= to_string(houses[i][0])+'#'+to_string(houses[i][1]);
          mp[tmp]=cnt++;
      }
      for(int i=0;i<n;i++){
           string tmp= to_string(houses[i][0])+'#'+to_string(houses[i][1]);
           for(int j=i+1;j<n;j++){
                   string tmp1=to_string(houses[j][0])+'#'+to_string(houses[j][1]);
                   int val=abs(houses[i][0]-houses[j][0]) + abs(houses[i][1]-houses[j][1]);
                   st.insert({val,{mp[tmp],mp[tmp1]}}); 
           }
           
      }
      int ans=0;
      rank.resize(n,0);
      parent.resize(n,0);
      iota(parent.begin(),parent.end(),0);
      for(auto it:st){
          
         int x=it.second.first;
         int y=it.second.second;
        //  cout<<it.first<<" "<<it.
         if(uni(x,y)){
             ans+=it.first;
         }
      }
      return ans;
      
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends