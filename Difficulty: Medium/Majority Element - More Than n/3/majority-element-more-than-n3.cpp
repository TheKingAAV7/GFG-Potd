class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        map<int,int>mp;
        int n=arr.size();
        for(int i:arr) mp[i]++;
        vector<int>ans;
        for(auto it:mp){
            if(it.second>n/3) ans.push_back(it.first);
        }
        return ans;
        
    }
};