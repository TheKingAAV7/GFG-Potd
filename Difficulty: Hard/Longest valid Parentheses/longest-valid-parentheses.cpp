//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string &s) {
       int n = s.length();
       vector<int> v(n, 0);
       stack<pair<char,int>> st;
       for (int i = 0; i < n; i++) {
           if (s[i] == '(') {
              st.push({'(', i});
           }
           else {
               if (!st.empty() && st.top().first == '(') {
                   auto x = st.top();
                   st.pop();
                   v[x.second] = (i - x.second + 1);
               }
           }
       }
       int ans = 0;
       // Corrected: sum only contiguous valid segments
       for (int i = 0; i < n; i++) {
           if (v[i] > 0) {
               int current = v[i];
               int j = i + v[i];
               while (j < n && v[j] > 0 && j == i + current) {
                   current += v[j];
                   j += v[j];
               }
               ans = max(ans, current);
               i = j - 1;  // skip over this contiguous block
           }
       }
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends