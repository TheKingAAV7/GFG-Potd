class Solution {
  public:
  
    vector<string> generateIp(string &s) {
        // code here
        vector<string>ans;
        int n=s.length();
        
        function<void(int,int, string&)>f=[&](int i, int cnt,string &cur)->void{
          if(i>=n){
              if(cnt==0){
              cur.pop_back();
              ans.push_back(cur);
              cur.push_back('.');
              }
              return;
          }  
          if(s[i]=='0'){
              cur.push_back(s[i]);
              cur.push_back('.');
              f(i+1,cnt-1,cur);
              cur.pop_back();
              cur.pop_back();
          }
          else{
              int num=0;
              for(int j=i;j<min(i+3,n);j++){
                  int len=j-i+1;
                  if(len==1){
                      num= s[j]-'0';
                  if(num>=1 and num<=255){
                      cur.push_back(s[j]);
                      cur.push_back('.');
                      f(j+1,cnt-1,cur);
                      cur.pop_back();
                      cur.pop_back();
                  }
                  }
                  else if(len==2){
                      num= (s[i]-'0')*10 + (s[i+1]-'0');
                      if(num>=1 and num<=255){
                      cur.push_back(s[i]);
                      cur.push_back(s[i+1]);
                      cur.push_back('.');
                      f(j+1,cnt-1,cur);
                      cur.pop_back();
                      cur.pop_back();
                      cur.pop_back();
                  }
                      
                  }
                  else{
                      num=(s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0');
                      if(num>=1 and num<=255){
                          cur.push_back(s[i]);
                          cur.push_back(s[i+1]);
                          cur.push_back(s[i+2]);
                          cur.push_back('.');
                          f(j+1,cnt-1,cur);
                          cur.pop_back();
                          cur.pop_back();
                          cur.pop_back();
                          cur.pop_back();
                      }
                  }
              }
          }
          return;
        };
        
        string cur;
        f(0,4,cur);
        return ans;
        
        
    }
};