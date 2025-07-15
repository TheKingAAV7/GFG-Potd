class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int tmp=0;
        for(char c:s){
            tmp=tmp*10+(c-'0');
            int rem=tmp%13;
            tmp=rem;
        }
        return tmp==0;
        

    }
};