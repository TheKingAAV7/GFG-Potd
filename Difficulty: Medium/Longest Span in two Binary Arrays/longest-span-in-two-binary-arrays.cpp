class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n=a1.size();
        vector<int>v(n);
        for(int i=0;i<n;i++) v[i]= a1[i]-a2[i];
        
        map<int,int>mp;
        mp[0]=-1;
        int ans=0;
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=v[i];
            if(mp.find(sm)!=mp.end()) ans=max(ans,i-mp[sm]);
            else mp[sm]=i;
        }
        return ans;
        
    }
};