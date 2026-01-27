class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        int sz1= n/2;
        int sz2= n-sz1;
        
        for(int b=0;b<(1<<sz1);b++){
            int sm=0;
            for(int i=0;i<sz1;i++){
                if((b>>i)&1){
                    sm+=arr[i];
                }
            }
            mp[sm]++;
        }
        int ans=0;
        
        for(int b=0;b<(1<<sz2);b++){
            int sm=0;
            for(int i=0;i<sz2;i++){
                if((b>>i)&1){
                    sm+=arr[n/2+i];
                }
            }
            int req= k-sm;
            ans+=mp[req];
        }
        return ans;
    }
};