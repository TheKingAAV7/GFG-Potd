class Solution {
  public:
    int substrCount(string &s, int k) {
       int n=s.length();
       int cnt=0;
       map<char,int>mp;
       for(int i=0;i<k;i++){
           mp[s[i]]++;
       }
       if(mp.size()==k-1) cnt++;
       for(int i=k;i<n;i++){
           mp[s[i]]++;
           mp[s[i-k]]--;
           if(mp[s[i-k]]==0) mp.erase(s[i-k]);
           if(mp.size()==k-1) cnt++;
       }
       return cnt;
        
    }
};