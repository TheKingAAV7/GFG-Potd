class Solution {
  public:
    int countStrings(string &s) {
        int n=s.length();
        vector<int>v(26,0);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            for(char c='a';c<='z';c++){
                if(c!=s[i] and v[c-'a']>0){
                    cnt+=v[c-'a'];
                }
            }
            v[s[i]-'a']++;
        }
        int maxi=*max_element(v.begin(),v.end());
        return maxi>=2?cnt+1: cnt;
        
    }
};
