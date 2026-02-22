class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>st;
        for(auto i:a) st.insert(i);
        for(auto i:b) st.insert(i);
        vector<int>ans(st.begin(),st.end());
        return ans;
        
        
    }
};