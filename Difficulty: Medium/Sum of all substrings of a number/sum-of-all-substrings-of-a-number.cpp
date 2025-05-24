class Solution {
  public:
    int sumSubstrings(string &s) {
        // 4 0   4+(37)+(259)+(1370)
        // 34 3
        // 234 23 2
        // 1234 123 12
        int n=s.length();
        int sm=0;
        int prev=0;
        int cnt=1;
        for(int i=n-1;i>=0;i--){
            int num=s[i]-'0';
            int tmp=  prev + (num*(pow(10,cnt)-1))/(9);
         
            
            sm+=tmp;
           
            prev=tmp;
            cnt++;
            
        }
        return sm;
    }
};