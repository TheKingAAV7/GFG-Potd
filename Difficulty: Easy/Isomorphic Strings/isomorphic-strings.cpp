class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        vector<int>mp(26,-1),mp1(26,-1);
        
        int n=s1.length();
        for(int i=0;i<n;i++){
            int cur= s1[i]-'a';
            int val= s2[i]-'a';
            if(mp[cur]==-1 and mp1[val]==-1){
                
                mp[cur]= val;
                mp1[val]=cur;
            }
            else{
                if(mp[cur]!=val || mp1[val]!=cur) return false;
            }
            
        }
        return true;
    }
};