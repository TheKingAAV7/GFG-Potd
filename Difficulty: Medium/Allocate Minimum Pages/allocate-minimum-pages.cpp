class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        int lo=1,hi=1e10;
        int ans=-1;
        auto f=[&](int mid)->bool{
          int sm=0;
          int cnt=1;
          for(int i=0;i<n;i++){
              if(arr[i]>mid) return false;
              if(sm+arr[i]<=mid){
                  sm+=arr[i];
              }
              else{
                  cnt++;
                  sm=arr[i];
              }
          }
          
          return cnt<=k;
        };
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};