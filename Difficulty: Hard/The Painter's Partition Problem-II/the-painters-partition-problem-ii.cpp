class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        
        int n=arr.size();
        
        int lo = 1;
        int hi = accumulate(arr.begin(),arr.end(),0ll);
        
        auto f= [&](int mid)->bool{
            int cnt=1;
            int cur=0;
            for(int i=0;i<n;i++){
                if(arr[i]>mid) return false;
                if(cur+arr[i]>mid){
                    cnt++;
                    cur=arr[i];
                }
                else cur+=arr[i];
            }
            
            
            return cnt<=k;
        };
        
        int ans= hi;        
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