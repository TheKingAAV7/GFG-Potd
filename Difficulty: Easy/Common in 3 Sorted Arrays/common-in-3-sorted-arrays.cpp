class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        
        map<int,int>mp;
        set<int>st;
        for(int &i:a) mp[i]=1;
        for(int &i:b) {
            if(mp[i]==1) mp[i]=2;
        }
        for(int &i:c){
            if(mp[i]==2) st.insert(i);
        }
        vector<int>ans(st.begin(),st.end());
        
        // sort(ans.begin(),ans.end());
        return ans;
        
    }
};