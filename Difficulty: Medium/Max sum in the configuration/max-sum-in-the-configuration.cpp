class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        map<int,int>mp;
        int sm=0;
        int psm=0;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            mp[i]=sm;
            psm+=arr[i]*i;
        }
        int ans=psm;
        for(int k=1;k<n;k++){
            // find diff; 
            // sum of first n-k
            int fsm= mp[n-k-1];
            int rsm= sm-fsm;
            int diff= k*(fsm) - (n-k)*(rsm);
            ans=max(ans,diff+psm);
        }
        return ans;
    }
};