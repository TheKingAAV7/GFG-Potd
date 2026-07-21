class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        vector<int>v;
        int n= arr.size();
        for(int i=0;i<n;i++){
            int x= arr[i];
            if(v.empty() || (x>v.back())) v.push_back(x);
            else{
                auto it= lower_bound(v.begin(),v.end(),x);
                int idx= it-v.begin();
                v[idx]=x;
            }
        }
        int sz= v.size();
        return n-sz;
    }
};