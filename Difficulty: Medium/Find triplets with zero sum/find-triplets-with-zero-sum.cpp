class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                    mp[arr[i]]--;
                    mp[arr[j]]--;
                    if(mp[arr[i]]==0) mp.erase(arr[i]);
                    if(mp[arr[j]]==0) mp.erase(arr[j]);
                    int sm=arr[i]+arr[j];
                    int req= -sm;
                    if(mp.find(req)!=mp.end()){
                        return true;
                    }
                    mp[arr[i]]++;
                    mp[arr[j]]++;
                }
            }
        }
        return false;
    }
};