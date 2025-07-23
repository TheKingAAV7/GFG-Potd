class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int lef=(i+1);
            int rig=(n-i);
            ans+=(lef*rig*arr[i]);
        }
        return ans;
    }
};