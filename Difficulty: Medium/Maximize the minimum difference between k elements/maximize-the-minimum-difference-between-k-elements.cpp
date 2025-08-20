class Solution {
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        int lo=1,hi=arr.back()-arr[0]+1;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            int cnt=1;
            int pos=0;
            while(pos<n){
                auto it=lower_bound(arr.begin()+pos,arr.end(),arr[pos]+mid);
                if(it==arr.end()) break;
                cnt++;
                pos=(it-arr.begin());
            }
            if(cnt>=k){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
        
    }
};
