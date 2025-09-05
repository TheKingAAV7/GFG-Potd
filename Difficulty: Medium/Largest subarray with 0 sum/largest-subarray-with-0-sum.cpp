class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        int sm=0;
        
        
        int ans= 0;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            if(sm==0) ans=max(ans,i+1);
            if(mp.find(sm)!=mp.end()){
               
                ans=max(ans,i-mp[sm]);
            }
            if(mp.find(sm)==mp.end()){
                mp[sm]=i;
            }
        }
        return ans;
    }
};