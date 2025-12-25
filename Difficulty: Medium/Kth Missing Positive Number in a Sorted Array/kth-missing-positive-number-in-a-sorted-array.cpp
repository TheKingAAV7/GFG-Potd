class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int tmp=k;
        int cur=1;
        unordered_set<int>st(arr.begin(),arr.end());
        int ele=-1;
        while(tmp>0){
            if(st.find(cur)==st.end()){
                tmp--;
                ele=cur;
            }
            cur++;
        }
        return ele;
        
    }
};