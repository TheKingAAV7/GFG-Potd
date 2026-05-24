class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        set<int>st(arr.begin(),arr.end());
        for(int i=start;i<=end;i++){
            if(st.find(i)==st.end()) return false;
        }
        
        return true;
        
    }
};
