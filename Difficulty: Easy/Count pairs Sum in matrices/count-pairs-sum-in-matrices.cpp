class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        map<int,int>mp;
        int ans=0;
        int n=mat1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[mat1[i][j]]++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mp.find(x-mat2[i][j])!=mp.end()){
                    ans++;
                }
            }
        }
        return ans;
    }
};