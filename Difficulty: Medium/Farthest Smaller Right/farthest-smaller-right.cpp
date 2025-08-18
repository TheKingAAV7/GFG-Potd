class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        map<int,int>mp;
        int n=arr.size();
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            auto it=mp.lower_bound(arr[i]);
            if(it!=mp.begin()) {
                it--;
                ans[i]= it->second; // 2.4 5.4
                
                mp[arr[i]]=max(mp[arr[i]],ans[i]);
            }
            else mp[arr[i]]=max(mp[arr[i]],i);
        }
        return ans;
    }
};