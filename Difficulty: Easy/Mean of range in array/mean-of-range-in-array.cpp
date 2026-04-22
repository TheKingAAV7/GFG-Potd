class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        
        int n= arr.size();
        vector<int> pref(n,0);
        int sm=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            pref[i]=sm;
        }
        for(auto &it:queries){
            int &l= it[0];
            int &r= it[1];
            int sz= r-l+1;
            int left= (l-1>=0)?pref[l-1]:0;
            int sm= pref[r]- left;
            ans.push_back(sm/sz);
        }
        return ans;
        
    }
};