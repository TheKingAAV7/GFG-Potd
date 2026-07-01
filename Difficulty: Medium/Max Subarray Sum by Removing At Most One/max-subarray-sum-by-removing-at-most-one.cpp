class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
       int n= arr.size();
       int mx= *max_element(arr.begin(),arr.end());
       if(mx<0) return mx;
       vector<int>dpp(n,0),dps(n,0);
       dpp[0] = max(0,arr[0]);
       for(int i=1;i<n;i++){
           dpp[i]= max({0,dpp[i-1]+arr[i],arr[i]});
       }
       int ans= *max_element(dpp.begin(),dpp.end());
       dps[n-1]= max(0,arr[n-1]);
       for(int i=n-2;i>=0;i--){
           dps[i]= max({0,arr[i]+dps[i+1],arr[i]});
       }
       for(int i=1;i<n-1;i++){
           ans=max(ans,dpp[i-1]+dps[i+1]);
       }
       return ans;
    }
};