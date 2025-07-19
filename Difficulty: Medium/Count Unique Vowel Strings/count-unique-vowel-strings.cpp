class Solution {
  private:
  int fact(int n){
      int ans=1;
      for(int i=1;i<=n;i++) ans*=i;
      return ans;
  }
  public:
    int vowelCount(string& s) {
        int cnt=0;
        int n=s.length();
        vector<char>vows={'a','e','i','o','u'};
        vector<int>mp(26,0);
        set<char>st={'a','e','i','o','u'};
        for(char ch:s){
            if(st.find(ch)!=st.end()){
                st.erase(ch);
            }
            mp[ch-'a']++;
            
        }
        int cntvow=5-(int)st.size();
        
        int ans=fact(cntvow);
       
        for(auto c:vows){
            if(mp[c-'a']>0){
                ans*=mp[c-'a'];
            }
        }
       if(cntvow==0) return 0;
       return ans; 
        
    }
};