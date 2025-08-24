class Solution {
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n=arr.size();
        int lo=1,hi=1e9;
        int ans=-1;
        auto f=[&](int mid)->bool{
          int cnt=0;
          int b=0;
          int l=0,i=0;
          while(i<n){
              
                 
              
                  if(arr[i]<=mid){
                      cnt++;
                     
                      if(cnt==k ){
                // if(mid==78) cout<<l<<" "<<i<<endl;
                  b++;
                 cnt=0;
              }
              
                  }
                  else{
                      cnt=0;
                  }
                  i++;
                  
                 
              
          }
          
          //if(i-l+1==k) b++;
          //if(mid==78)
          //cout<<mid<<" "<<b<<endl;
          return b>=m;
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