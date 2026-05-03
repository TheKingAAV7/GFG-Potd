class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        string s;
        while(N>0){
            if(N&1) s.push_back('1');
            else s.push_back('0');
            N>>=1;
        }
        string r= s;
        reverse(s.begin(),s.end());
        return s==r;
    }
};