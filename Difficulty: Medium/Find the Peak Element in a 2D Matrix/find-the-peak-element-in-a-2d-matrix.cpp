class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool yes= true;
                int one= (i-1>=0)?(mat[i-1][j]<=mat[i][j]):true;
                int two= (j-1>=0)?(mat[i][j-1]<=mat[i][j]):true;
                int three= (i+1<n)?(mat[i+1][j]<=mat[i][j]):true;
                int four= (j+1<m)?(mat[i][j+1]<=mat[i][j]):true;
                if(one and two and three and four){
                    return {i,j};
                    //ans.push_back(mat[i][j]);
                }
            }
        }
        // for(int i:ans) cout<<i<<" ";
        // cout<<endl;
     
        // sort(ans.begin(),ans.end());
        // if(ans.empty()) ans;
        return {-1,-1};
    }
};
