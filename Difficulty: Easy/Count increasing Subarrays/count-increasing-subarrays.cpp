class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n=arr.size();
        int cnt=0;
        int p=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]>p) cnt++;
            else{
                ans+=cnt*(cnt+1)/2 - cnt;
                cnt=1;
             
            }
            p=arr[i];
        }
        ans+=cnt*(cnt+1)/2 - cnt;
        return ans;
    }
};
