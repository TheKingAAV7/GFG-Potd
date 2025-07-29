class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int,int>mp;
        int sm=0;
        int ans=0;
        int n=arr.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            int req=sm-k;
            ans+=mp[req];
            mp[sm]++;
        }
        return ans;
        
    }
};