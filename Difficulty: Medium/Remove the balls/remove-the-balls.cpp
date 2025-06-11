class Solution {
  public:
    int findLength(vector<int> &c, vector<int> &r) {
        vector<pair<int,int>>v;
        int n=c.size();
        for(int i=0;i<n;i++){
            v.push_back({c[i],r[i]});
        }
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
           if(!st.empty() and st.top()==v[i]){
               st.pop();
           }
           else st.push({c[i],r[i]});
        }
        return st.size();
    }
};