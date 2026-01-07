class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        
        int n=arr.size();
        map<int,int>mp;
        int ans=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            if(arr[i]&1) cnt++;
            int req= cnt-k;
            if(mp.find(req)!=mp.end()) ans+=mp[req];
            mp[cnt]++;
        }
        return ans;
        
    }
};