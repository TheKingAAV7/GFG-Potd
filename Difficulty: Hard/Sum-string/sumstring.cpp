class Solution {

  public:
   vector<int>dp;
  string sm(const string &a, const string &b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res;
    // add from least significant digit up
    while (i >= 0 || j >= 0 || carry) {
        int da = (i >= 0 ? a[i--] - '0' : 0);
        int db = (j >= 0 ? b[j--] - '0' : 0);
        int sum = da + db + carry;
        carry = sum / 10;
        res.push_back(char('0' + (sum % 10)));
    }
    // res is reversed:
    reverse(res.begin(), res.end());
    // strip any leading zeros (just in case)
    int pos = 0;
    while (pos + 1 < (int)res.size() && res[pos] == '0') pos++;
    return res.substr(pos);
}
 
  bool f(int i,string &s,int &n,string a,string b,int cnt){
      
    if(i>=n) return cnt>=2;
   
    bool ans=false;
    if(cnt==1){
      if(s[i]=='0'){
         ans|= f(i+1,s,n,a,"0",cnt+1);
      }
      else{
          string tmp="";
          for(int idx=i;idx<n-1;idx++){
              tmp.push_back(s[idx]);
             
              ans|=f(idx+1,s,n,a,tmp,cnt+1);
          }
      }
      return ans;
    }
   if(s[i]=='0'){
       if(sm(a,b)=="0"){
           ans|=f(i+1,s,n,b,"0",cnt);
       }
   }
   else{
       string tmp="";
       for(int idx=i;idx<n;idx++){
           tmp.push_back(s[idx]);
           if(sm(a,b)==tmp){
               ans|=f(idx+1,s,n,b,tmp,cnt);
           }
       }
   }
   return ans;
  }
    bool isSumString(string &s) {
       int n=s.length();
       dp.resize(n);
       fill(dp.begin(),dp.end(),-1);
       string tmp="";
       string a,b;
       b="";
       a="";
       int cnt=0;
       bool ans=false;
       if(s[0]=='0'){
           a="0";
           
          ans= f(1,s,n,a,b,cnt+1);
          return ans;
       }
       for(int i=0;i<n-2;i++){
           a.push_back(s[i]);
           ans|=f(i+1,s,n,a,b,cnt+1);
       }
       return ans;
       
        
    }
};