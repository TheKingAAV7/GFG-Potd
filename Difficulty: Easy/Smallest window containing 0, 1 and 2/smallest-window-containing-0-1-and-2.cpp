class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n= s.length();
        int mp[3]={0,0,0};
        int ans=n+1;
        int l=0;
        for(int i=0;i<n;i++){
         mp[s[i]-'0']++;
         while(mp[0]>=1 and mp[1]>=1 and mp[2]>=1){
             ans=min(ans,i-l+1);
             mp[s[l]-'0']--;
             l++;
         }
        }
        return ans==(n+1)?-1:ans;
        
    }
};
