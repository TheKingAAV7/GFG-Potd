class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        // 0 2 4
        // 0 2 4 5
        int n= arr.size();
        int cnt=0;
        for(int i:arr) cnt+=(i==1);
        if(cnt==0) return -1;
        int ans=INT_MAX;
        int l=0;
        int cost=0;
        for(int i=0;i<cnt;i++){
            if(arr[i]==0) cost++;
        }
        ans=min(ans,cost);
        for(int i=cnt;i<n;i++){
            if(arr[i-cnt]==0) cost--;
            if(arr[i]==0) cost++;
            ans=min(ans,cost);
        }
        return ans;
        
    }
};