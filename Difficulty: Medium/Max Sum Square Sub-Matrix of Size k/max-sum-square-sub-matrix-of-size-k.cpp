class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        
        int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>>pref(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up= (i-1>=0 ? pref[i-1][j] : 0);
                int left= (j-1>=0 ? pref[i][j-1] : 0);
                int comm= (i-1>=0 and j-1>=0 )? pref[i-1][j-1] : 0;
                pref[i][j]= up+left-comm + mat[i][j];
            }
        }
        
        k--;
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-k>=0 and j-k>=0){
                    int ur= i-k;
                    int uc= j-k;
                    int total= pref[i][j];
                    int up= (ur-1>=0 ? pref[ur-1][j] : 0);
                    int left= (uc-1>=0 ? pref[i][uc-1] : 0);
                    int comm= (ur-1>=0 and uc-1>=0)? pref[ur-1][uc-1]:0;
                    int sm= total-up-left+comm;
                    // cout<<ur<<" "<<uc<<' '<<i<<" "<<j<<" -> "<<sm<<endl;
                    ans=max(ans,sm);
                }
            }
        }
        return ans;
        
    }
};