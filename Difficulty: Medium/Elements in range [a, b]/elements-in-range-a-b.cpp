class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(auto it:queries){
            int l= it[0];
            int r= it[1];
            auto lit= lower_bound(arr.begin(),arr.end(),l);
            auto rit= upper_bound(arr.begin(),arr.end(),r);
            int lidx= lit-arr.begin();
            int ridx= rit-arr.begin();
            ans.push_back(ridx-lidx);
        }
        return ans;
        
    }
};