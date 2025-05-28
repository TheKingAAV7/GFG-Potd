class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=j+1;k<m;k++){
                   
                    //up
                    if(mat[i][j] and mat[i][k] and vis[j][k]==1){
                      
                        return true;
                    }
                    if(mat[i][j] and mat[i][k])
                    vis[j][k]=1;
                   
                    
                }
            }
        }
        return false;
        
    }
};