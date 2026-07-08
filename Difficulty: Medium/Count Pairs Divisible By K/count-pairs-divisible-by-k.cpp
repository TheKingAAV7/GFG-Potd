class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // 2 
        int n= arr.size();
        map<int,int>mp;
        
        int ans=0;
        for(int i=0;i<n;i++){
            int cur= arr[i]%k;
            int req= ((k-cur+k)%k);
            ans+=mp[req];
            mp[cur]++;
        }
        return ans;
    }
};