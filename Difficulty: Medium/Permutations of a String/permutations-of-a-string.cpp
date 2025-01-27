//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<string> findPermutation(string &s) {
       set<string>st;
       sort(s.begin(),s.end());
      //int n=s.length();
       do {
          st.insert(s);
        
    } while (next_permutation(s.begin(), s.end()));
   // st.insert(s);
    vector<string>ans(st.begin(),st.end());
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends