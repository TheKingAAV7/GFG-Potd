class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            if(mp[arr[i]]>=2) ans.push_back(arr[i]);
        }
        return ans;
        
    }
};