class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n=arr.size();
        vector<int>smx(n,0);
        int mx=0;
        for(int i=n-1;i>=0;i--){
            smx[i]=mx;
            mx=max(mx,arr[i]);
        }
        int mn=1e9;
        for(int i=0;i<n;i++){
            
            if(mn < arr[i] and arr[i] < smx[i]){
                return {mn,arr[i],smx[i]};
            }
            mn=min(mn,arr[i]);
        }
        return {};
        
    }
};