class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n= arr.size();
        int cnt=1;
        // for(int i:arr) cout<<i<<" ";
        // cout<<endl;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]!=1) {
                cnt++;
            }
        }
        return cnt;
    }
};
