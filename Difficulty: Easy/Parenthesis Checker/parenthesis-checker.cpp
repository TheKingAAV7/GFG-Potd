//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char>st;
        int n=s.length();
        map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        for(int i=0;i<n;i++){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(!st.empty() and st.top()==mp[s[i]]){
                  st.pop();  
                }
                else return false;
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends