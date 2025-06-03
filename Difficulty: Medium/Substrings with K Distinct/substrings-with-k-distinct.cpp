class Solution {
  public:
    int countSubstr(string& s, int k) {
        int n=s.length();
        int cnt1=0,cnt2=0;
        int l=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp.size()>=k){
                cnt1+=(n-i);
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
        }
        l=0;
        mp.clear();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp.size()>k){
                cnt2+=(n-i);
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
        }
        return cnt1-cnt2;
    }
};