class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // 0 6 3 2
        // 1 0 0 0 1
        // 1 
        
        int n= queries.size();
        vector<int>v;
        v.push_back(0);
        vector<int>mp(n+1,0);
        for(auto &it:queries){
            if(it[0]==0){
                v.push_back(it[1]);
            }
            else{
                mp[0]^=it[1];
                int sz= v.size();
                mp[sz]^= it[1];
            }
        }
        int cur=0;
        for(int i=0;i<v.size();i++){
            cur^=mp[i];
            v[i]^=cur;
        }
        sort(v.begin(),v.end());
        return v;
        
        
    }
};
