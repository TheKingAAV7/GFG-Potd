class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
       int n=mat.size();
       for(int i=0;i<n;i++){
           bool isceleb1=true,isceleb2=true;
           for(int j=0;j<n;j++){
               if(mat[i][j] and i!=j){
                   isceleb1=false;
                   break;
               }
           }
           if(isceleb1){
               for(int j=0;j<n;j++){
                   if(!mat[j][i]){
                       isceleb2=false;
                       break;
                   }
               }
               if(isceleb2){
                   return i;
               }
           }
       }
       return -1;
        
    }
};