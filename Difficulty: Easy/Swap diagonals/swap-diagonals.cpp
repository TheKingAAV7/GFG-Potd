class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here (0,2) (1,1) ()
        /*
        
        
        
        */
        int n=mat.size();
        for(int i=0;i<n;i++){
            swap(mat[i][i],mat[i][n-i-1]);
        }
        return;
 
    }
};
