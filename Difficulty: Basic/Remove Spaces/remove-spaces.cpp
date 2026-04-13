class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string ans;
        for(char c: s){
            if(c!=' ') ans.push_back(c);
        }
        return ans;
        
    }
};