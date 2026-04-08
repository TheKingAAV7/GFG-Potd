class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        set<int>tmp;
        set<int>st(a.begin(),a.end());
        for(int i:b){
            if(st.find(i)!=st.end()) tmp.insert(i);
        }
        vector<int>ans(tmp.begin(),tmp.end());
        return ans;
        
        
    }
};