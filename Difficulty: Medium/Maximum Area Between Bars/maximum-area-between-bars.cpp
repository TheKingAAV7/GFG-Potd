class Solution {
  public:
    int maxArea(vector<int> &arr) {
        // code here
        int n= arr.size();
        int lo=0,hi=n-1;
        int ans=0;
        while(lo<=hi){
            ans=max(ans,(hi-lo-1)*min(arr[lo],arr[hi]));
            if(arr[lo]<=arr[hi]) lo++;
            else hi--;
        }
        return ans;
    }
};