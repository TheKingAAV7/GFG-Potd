class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int ans=0;
        int n=mat.size();
        int m= mat[0].size();
        vector<vector<int>>pref(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up= i>=1?pref[i-1][j]: 0;
                int left= j>=1? pref[i][j-1]:0;
                int corner= (i>=1 and j>=1)? pref[i-1][j-1]: 0;
                pref[i][j]= mat[i][j]+up+left-corner;
            }
        }
        //cout<<pref[n-1][m-1]<<endl;
        
        for(int len= 1;len<=min(n,m);len++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int ri= i+len-1;
                    int rj= j+len-1;
                    if(ri<n and rj<m){
                        int total= pref[ri][rj];
                        int up= (i-1>=0) ? pref[i-1][rj] : 0;
                        int left= (j-1>=0)? pref[ri][j-1]: 0;
                        int corner= (i-1>=0 and j-1>=0)? pref[i-1][j-1]: 0;
                        
                        
                        int cursm= total - up - left + 2*corner;
                        if(cursm==x) ans++;
                    }
                }
            }
        }
        return ans;
    }
};