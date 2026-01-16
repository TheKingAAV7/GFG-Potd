class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        /*
        
        
        Definition of Redundant parenthesis
        
        same sub-expression is surrounded by unencessary or multiple brackes..
        
        
        (b+((c+d)+e)
        
        a+ /c
        */
        stack<string>st;
        stack<char>par;
        

        
        int n=s.length();
        for(int i=1;i<n-1;i++){
            if(s[i]!='(' and s[i]!=')'){
                if(s[i-1]=='(' and s[i+1]==')') return true;
            }
        }
        
        st.push("");
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push("");
                par.push('(');
            }
            else if(s[i]==')'){
                if(st.top()=="") return true;
                st.pop();
                par.pop();
            }
            else{
                string lst= st.top();
                st.pop();
                lst.push_back(s[i]);
                st.push(lst);   
            }
        }
        return false;
    }
};
