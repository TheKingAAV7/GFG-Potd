class Solution {
  public:
  void f(string &s,vector<string>&v,int n){
      if(s.size()==n){
          v.push_back(s);
          return ;
      }
      s.push_back('0');
      f(s,v,n);
      s.pop_back();
      s.push_back('1');
      f(s,v,n);
      s.pop_back();
      return ;
  }
    vector<string> binstr(int n) {
        // code here
        vector<string>v;
        string s="";
        f(s,v,n);
        sort(v.begin(),v.end());
        return v;
    }
};