class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>sweep(n+1,0);
        int xo=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            xo^=sweep[i];
            arr[i]^=xo;
            if(arr[i]==1) continue;
            int rig=i+k;
            if(i+k>n) return -1;
            cnt++;
            sweep[i]=1;
            sweep[rig]=1;
            xo^=1;
            
        }
        return cnt;
    }
};