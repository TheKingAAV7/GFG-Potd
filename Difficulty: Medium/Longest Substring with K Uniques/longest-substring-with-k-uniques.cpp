class Solution {
  private:
  int f(string s, int k){
      map<char,int>mp;
      int n=s.length();
      int l=0;
      int cnt=-1;
      for(int i=0;i<n;i++){
          mp[s[i]]++;
          while(mp.size()>k){
              mp[s[l]]--;
              if(mp[s[l]]==0) mp.erase(s[l]);
              l++;
          }
          if(mp.size()==k)
          cnt= max(cnt,(i-l+1));
      }
      return cnt;
  }
  public:
    int longestKSubstr(string &s, int k) {
       
       return f(s,k);
        
    }
};