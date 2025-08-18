class Solution {
  public:
    int hIndex(vector<int>& ct) {
        // code here
        sort(ct.begin(),ct.end());
        
        int n=ct.size();
        int maxi=-1;
        int lo=0,hi=ct.back();
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            auto it=lower_bound(ct.begin(),ct.end(),mid);
            if(it!=ct.end()){
            int idx=it-ct.begin();
            int cnt=n-idx;
            if(cnt>=mid){
                maxi=mid;
                lo=mid+1;
            }
            else hi=mid-1;
            }
            else hi=mid-1;
        }
        return maxi;
    }
};