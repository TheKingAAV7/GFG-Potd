class Solution {
  public:
    string maxSubseq(string& s, int k) {
        stack<char>st;
        for(char c:s){
            // i
            while(k>0 and !st.empty() and c>st.top()){
                st.pop();
                k--;
                
                
            }
            st.push(c);
            
        }
        string ans="";
        while(!st.empty() and k){
            st.pop();
            k--;
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
}
};
