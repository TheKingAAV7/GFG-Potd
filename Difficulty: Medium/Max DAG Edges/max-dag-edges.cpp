class Solution {
  public:
    int maxEdgesToAdd(int n, vector<vector<int>>& edges) {
        // code here
        
        return (n*(n-1))/2 - (int)(edges.size());
        
    }
};
