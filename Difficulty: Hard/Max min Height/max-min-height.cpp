class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int K, int w) {
        // code here
        int n=arr.size();
        int lo=INT_MAX,hi=-1;
        for(int i:arr) {
            lo= min(lo,i);
            hi= max(hi,i);
        }
        hi= INT_MAX;
        int ans= lo;
        
        auto f=[&](int mid)->bool{
           
          vector<int>pref(n+1,0);
          int runningsm=0;
          int k=K;
          for(int i=0;i<n;i++){
              runningsm+=pref[i];
              int curval=arr[i]+runningsm;
              if(curval<mid){
                  int req= (mid-curval);
                  //if(mid==6) cout<<i<<" "<<k<<endl;
                  if(k<req) return false;
                  pref[i]+=(req);
                  pref[min(n,i+w)]-=req;
                  runningsm+=req;
                  k-=req;
              }
          }
          return true;
            
        };
        
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans= mid;
                lo=mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};