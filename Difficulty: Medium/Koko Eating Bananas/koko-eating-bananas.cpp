class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
       int n=arr.size();
       int lo=1,hi=*max_element(arr.begin(),arr.end());
       int ans=hi;
       auto f=[&](int mid)->bool{
           int cnt=0;
         for(int i:arr){
             cnt+=ceil((i*1.0)/(mid*1.0));
         }  
         return k>=cnt;
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