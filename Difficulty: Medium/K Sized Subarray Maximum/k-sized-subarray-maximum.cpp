class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        ans.push_back(mp.rbegin()->first);
        for(int i=k;i<n;i++){
            mp[arr[i-k]]--;
            if(mp[arr[i-k]]==0) mp.erase(arr[i-k]);
            mp[arr[i]]++;
            ans.push_back(mp.rbegin()->first);
        }
        return ans;
        
    }
};