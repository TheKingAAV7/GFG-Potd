class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int>mp(26,0);
        for(char &c:s) mp[c-'a']++;
        int od=0;
        for(int &i:mp){
            od+=(i&1);
        }
        return od<=1;
        
    }
};