class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        for(int i=0;i+m-1<n;i++){
            ans=min(ans,a[i+m-1]-a[i]);
        }
        return ans;
        
    }
};