class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        vector<int>tmp(arr.begin(),arr.end());
        int cntreq=-1;
        int ans1=-1;
        if(n%2==0){
            cntreq=n-(n/2)+1;
            
            int idx=n/2;
            tmp[idx-1]+=k;
            sort(tmp.begin(),tmp.end());
            ans1=(tmp[idx]+tmp[idx-1])/2;
            // A
            
        }
        else{
            cntreq=n-n/2;
            
              
        }
       // cout<<cntreq<<endl;
        int lo=0,hi=1e9;
        int ans=-1;
        auto f=[&](int mid)->bool{
          int cst=0;
          
              auto it=lower_bound(arr.begin(),arr.end(),mid);
              if(it==arr.begin()) return true;
              it--;
              int idx=it-arr.begin();
              int cnt=n-idx-1;
              while(idx>=0 and cst<k){
                  int reqcst=mid-arr[idx];
                  if(cst+reqcst<=k){
                      cst+=reqcst;
                      cnt++;
                      idx--;
                  }
                  else break;
              }
              return cnt>=cntreq;

        };
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return max(ans,ans1);
        
    }
};