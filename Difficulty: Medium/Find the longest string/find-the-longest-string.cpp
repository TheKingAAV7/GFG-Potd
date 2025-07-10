class Solution {
  public:
    string longestString(vector<string> &words) {
        unordered_set<string>st;
        for(auto it:words) st.insert(it);
        sort(words.begin(),words.end(),[&](string &a, string &b)->bool{
           if(a.length()==b.length()) return a<b;
           return a.length()>b.length();
        });
        for(auto it:words){
            string tmp="";
            bool f=true;
            for(char c:it) {
                tmp.push_back(c);
                if(st.find(tmp)==st.end()){
                    f=false;
                    break;
                }
            }
            if(f) return it;
        }
        return "";
    }
};