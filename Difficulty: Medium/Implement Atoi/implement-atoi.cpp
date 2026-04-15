class Solution {
  public:
    int myAtoi(string &s) {
        // code here'
        int n=s.length();
        int i=0;
        int num=0;
        int neg=0;
        int dig=0;
        int mx=2147483647;
        while(i<n and s[i]==' ')i++;
        
        if(i>=n) return 0;
        if(s[i]=='-' || s[i]=='+'){
            // cout<<"es"<<endl;
        neg= (s[i]=='-');
        i++;
        if(i>=n) return 0;
        }

        // cout<<neg<<endl;

        while(i<n and s[i]>='0' and s[i]<='9'){
            int cur=s[i]-'0';
            if(num>=(mx-cur)/10 ){
                if(neg) return -2147483648;
                else return 2147483647;
            }
            else{
                num=(num*10)+cur;
            }
            dig=1;
            i++;
        }
        if(dig==0) return 0;
        if(neg) return -1*num;
        return num;
        
    }
};
