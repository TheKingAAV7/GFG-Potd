class Solution {
  public:
    int reverseExponentiation(int n) {
        // code here
        int rev=0;
        int prev=n;
        while(prev>0){
            int ls=prev%10;
            prev/=10;
            rev=rev*10+ls;
        }
        return pow(n,rev);
    }
};