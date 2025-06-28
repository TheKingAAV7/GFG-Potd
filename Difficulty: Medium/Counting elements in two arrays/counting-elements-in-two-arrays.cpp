class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int>mp(1e5+1,0);
        for(int i:b){
            mp[i]++;
        }
        for(int i=1;i<=1e5;i++){
            mp[i]+=mp[i-1];
        }        
        vector<int>ans;
        for(int i:a) ans.push_back(mp[i]);
        return ans;
    }
};