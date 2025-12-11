class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
       int n=mat.size();
       int sz=n/2;
       for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
              // cout<<i<<" "<<j<<" "<<j<<" "<<i<<endl;
               swap(mat[i][j],mat[j][i]);
           }
       }
       
       return mat;
        
    }
};