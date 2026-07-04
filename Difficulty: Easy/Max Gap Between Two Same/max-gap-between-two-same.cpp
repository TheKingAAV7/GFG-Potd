class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        
        vector<int>v(26,-1);
        int n= s.length();
        int ans=-1;
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']==-1) v[s[i]-'a']=i;
            else ans=max(ans,i-v[s[i]-'a']-1);
        }
        return ans;
    }
};