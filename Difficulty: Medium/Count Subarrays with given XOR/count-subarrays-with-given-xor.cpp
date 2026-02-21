class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        map<long,long>mp;
        int n=arr.size();
        mp[0]=1;
        long xo=0;
        long ans=0;
        for(int i=0;i<n;i++){
            xo^=arr[i];
            long req= xo^k;
            ans+=mp[req];
            mp[xo]+=1;
        }
        return ans;
        
    }
};