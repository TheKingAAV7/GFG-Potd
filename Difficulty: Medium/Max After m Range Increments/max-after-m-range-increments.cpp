class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int>mp(n+1,0);
        int sz= a.size();
        int mx=0;
        for(int i=0;i<sz;i++){
            int lef= a[i];
            int rig= b[i];
            int diff= k[i];
            mp[lef]+=diff;
            mp[rig+1]-=diff;
        }
        for(int i=1;i<n;i++){
            mp[i]+=mp[i-1];
            mx=max(mx, mp[i]);
        }
        return max(mp[0],mx);
        
        
    }
};