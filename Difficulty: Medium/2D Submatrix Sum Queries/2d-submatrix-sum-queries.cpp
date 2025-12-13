class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pref(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur= mat[i][j];
                int up= (i-1>=0)? pref[i-1][j]:0;
                int left= (j-1>=0)? pref[i][j-1]:0;
                int upleft= (i-1>=0 and j-1>=0)?pref[i-1][j-1]:0;
                pref[i][j]= cur+up+left-upleft;
            }
        }
        vector<int>ans;
        for(auto it:queries){
            int r1= it[0];
            int c1= it[1];
            int r2= it[2];
            int c2= it[3];
            
            int total = pref[r2][c2];
            int up = (r1-1>=0) ? pref[r1-1][c2]:0;
            int left= (c1-1>=0) ? pref[r2][c1-1]:0;
            int upleft= (r1-1>=0 and c1-1>=0)?pref[r1-1][c1-1]:0;
            
            int res= total - up - left + upleft;
            ans.push_back(res);
        }
        return ans;
        
    }
};
