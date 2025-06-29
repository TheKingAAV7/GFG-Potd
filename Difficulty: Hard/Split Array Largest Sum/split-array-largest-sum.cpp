class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        int lo=1,hi=accumulate(arr.begin(),arr.end(),0);
        int ans=hi;
        auto f=[&](int mid)->bool{
           int sm=0;
           int cnt=1;
           for(int i=0;i<n;i++){
               if(arr[i]>mid) return false;
               if(sm+arr[i]<=mid){
                   sm+=arr[i];
               }
               else{
                   sm=arr[i];
                   cnt++;
               }
           }
           
           return cnt<=k;
        };
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};