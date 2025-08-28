class Solution {
  public:
    string smallestWindow(string &s, string &p) {
       int n=s.length();
       vector<int>mp(26,0);
       for(char c:p) mp[c-'a']++;
       int sz=INT_MAX;
       int lef=-1,r=-1;
       int l=0;
       for(int i=0;i<n;i++){
           mp[s[i]-'a']--;
           while(*max_element(mp.begin(),mp.end())==0){
               if(i-l+1<sz){
                   sz=i-l+1;
                   lef=l;
                   r=i;
               }
               mp[s[l]-'a']++;
               l++;
           }
       }
       if(sz==INT_MAX) return "";
       return s.substr(lef,sz);
    }
};