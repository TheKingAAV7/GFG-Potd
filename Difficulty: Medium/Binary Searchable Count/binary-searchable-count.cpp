class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        // code here
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int lo= 0, hi= n-1;
            int x= arr[i];
            bool ans=false;
            while(lo<=hi){
                int mid= lo+(hi-lo)/2;
                if(arr[mid]==x){
                    ans=true;
                    break;
                }
                if(arr[mid]<x) lo=mid+1;
                else hi=mid-1;
            }
            cnt+=ans;
        }
        return cnt;
        
    }
};