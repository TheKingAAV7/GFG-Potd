class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n= s.length();
        int ans=-1;
        map<char,int>mp;
        int l=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()==k) ans= max(ans, i-l+1);
        }
        return ans;
    }
};