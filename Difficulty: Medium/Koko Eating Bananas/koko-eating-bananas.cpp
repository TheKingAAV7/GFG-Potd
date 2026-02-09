class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int mx=*max_element(arr.begin(),arr.end());
        int lo=1,hi=mx;
        int ans=-1;
        auto f=[&](int mid)->bool{
          int hrs=0;
          for(int i=0;i<n;i++){
              int req= ceil(1.0*arr[i]/mid);
              hrs+=req;
          }
          return hrs<=k;
        };
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans= mid;
                hi=mid-1;
            }
            else lo= mid+1;
        }
        return ans;
    }
};