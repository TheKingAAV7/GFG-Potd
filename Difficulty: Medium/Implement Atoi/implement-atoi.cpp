//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
       int i = 0;
    
    // Skip leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // Check for sign
    bool sign = true;
    if (s[i] == '-') {
        sign = false;
        i++;
    }

    int num = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        
        // Handle overflow and underflow
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return sign ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;
        i++;
    }

    return sign ? num : -num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends