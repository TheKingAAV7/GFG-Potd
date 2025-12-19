class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        auto it=lower_bound(arr.begin(),arr.end(),k);
        if(it==arr.end()){
            return arr.size();
        }
        int idx= it-arr.begin();
        return idx;
    }
};