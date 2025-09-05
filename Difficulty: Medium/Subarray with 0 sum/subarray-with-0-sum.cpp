class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
       int n=arr.size();
       unordered_map<int,int>mp;
       int sm=0;
       for(int i=0;i<n;i++){
           sm+=arr[i];
           if(sm==0 || arr[i]==0) return true;
           int req= sm;
           if(mp.find(req)!=mp.end()) return true;
           mp[sm]=1;
       }
       return false;
    }
};