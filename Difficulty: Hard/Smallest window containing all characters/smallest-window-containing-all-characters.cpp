class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n=s.length();
        int m=p.length();
        vector<int>mp(26,-1e7);
        for(int i=0;i<m;i++){
            if(mp[p[i]-'a']==-1e7){
                mp[p[i]-'a']=1;
            }
            else
            mp[p[i]-'a']++;
        }
        
        int al,ar;
        al=ar=-1;
        int l=0;
        int len=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]-'a']!=-1e7)
            mp[s[i]-'a']--;
            while(*max_element(mp.begin(),mp.end())<=0){
                 int curlen= i-l+1;
                 if(curlen<len){
                     al=l;
                     ar=i;
                     len=curlen;
                 }
                 
                if(mp[s[l]]!=-1e7){
                    mp[s[l]-'a']++;
                }
                l++;
            }
            
        }
        if(al==-1) return "";
        return s.substr(al,len);
        
    }
};