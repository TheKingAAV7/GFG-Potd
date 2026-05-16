class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        
        int n= arr.size();
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!ans.empty()){
              int lef= ans.back()>=0;
              int cur= arr[i]>=0;
              if(lef!=cur) ans.pop_back();
              else ans.push_back(arr[i]);
            }
            else ans.push_back(arr[i]);
        }
        return ans;
        
    }
};