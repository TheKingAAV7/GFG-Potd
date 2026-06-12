class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i+=k){
            string t=s.substr(i,k);
            mp[t]++;
        }
        if(mp.size()>2) return false;
        int count=0;
        for(auto it:mp){
            if(it.second>1) count++;
        }
        return count<2;
    }
};