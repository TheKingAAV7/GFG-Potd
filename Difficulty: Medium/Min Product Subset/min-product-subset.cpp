class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        
        int n= arr.size();
        
        int ans=1e9;
        for(int b=1;b<(1<<n);b++){
            int prod=1;
            for(int i=0;i<n;i++){
                int idx= (n-i-1);
                if((b>>idx)&1) prod*=arr[idx];
            }
            ans=min(ans,prod);
        }
        return ans;
        
        
        
    }
};