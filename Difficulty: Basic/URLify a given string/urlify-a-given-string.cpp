class Solution {
  public:
    string URLify(string &s) {
        // code here
        string ans;
        for(char &c:s){
            if(c==' '){
                ans+="%20";
            }
            else ans.push_back(c);
        }
        return ans;
        
    }
};