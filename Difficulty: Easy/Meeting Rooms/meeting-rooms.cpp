class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        int l=-1,r=-1;
        for(auto it:arr){
            int start= it[0];
            int end  = it[1];
            if(start>=r){
                l=start;
                r=end;
            }
            else return false;
        }
        return true;
    }
};