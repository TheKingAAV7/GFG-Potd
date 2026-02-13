class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int sm=accumulate(arr.begin(),arr.end(),0);
        int lo=1, hi= sm;
        int ans=hi;
        auto f=[&](int mid)->bool{
          int cnt=1;
          int cursm=0;
          for(int i=0;i<n;i++){
              if(arr[i]>mid) return false;
              if(cursm+arr[i]<=mid) cursm+=arr[i];
              else {
                  cnt++;
                  cursm=arr[i];
              }
          }
          return cnt<=k;
        };
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};