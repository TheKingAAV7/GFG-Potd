class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here  1 2 4 10
        sort(arr.begin(),arr.end());
        int n= arr.size();
        int ans=0;
        for(int i=0;i<n;i+=1){
            int x= arr[i];
            int req = x+k;
            auto it= lower_bound(arr.begin(),arr.end(),req);
            it--;
            int idx= it - arr.begin();
            // cout << idx<<endl;
            int cnt= idx-i;
            ans+=cnt;
        }
        return ans;
        
    }
};