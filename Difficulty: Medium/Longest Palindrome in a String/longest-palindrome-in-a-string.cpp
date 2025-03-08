//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Helper function: Checks if there's a palindrome of length L.
    // If found, it sets 'startIndex' to its starting index and returns true.
    bool checkPalindrome(const string &s, int L, int &startIndex) {
        int n = s.size();
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            bool isPal = true;
            for (int k = 0; k < L/2; k++) {
                if (s[i + k] != s[j - k]) {
                    isPal = false;
                    break;
                }
            }
            if (isPal) {
                startIndex = i;
                return true;
            }
        }
        return false;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        // Variables to store the best found palindromes for odd and even lengths.
        int bestOddLen = 1, bestOddStart = 0;
        int bestEvenLen = 0, bestEvenStart = 0;
        
        // Binary search for odd-length palindromes.
        int low = 1, high = (n % 2 == 1 ? n : n - 1);  // highest odd number ≤ n
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Ensure mid is odd.
            if (mid % 2 == 0) mid--;  
            if (mid < low) mid = low;
            
            int start;
            if (checkPalindrome(s, mid, start)) {
                bestOddLen = mid;
                bestOddStart = start;
                low = mid + 2; // Try to find a longer odd palindrome.
            } else {
                high = mid - 2;
            }
        }
        
        // Binary search for even-length palindromes.
        low = 2, high = (n % 2 == 0 ? n : n - 1);  // highest even number ≤ n
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Ensure mid is even.
            if (mid % 2 == 1) mid--;  
            if (mid < low) mid = low;
            
            int start;
            if (checkPalindrome(s, mid, start)) {
                bestEvenLen = mid;
                bestEvenStart = start;
                low = mid + 2; // Try to find a longer even palindrome.
            } else {
                high = mid - 2;
            }
        }
        
        // Choose the longer palindrome between odd and even.
        if (bestOddLen >= bestEvenLen)
            return s.substr(bestOddStart, bestOddLen);
        else
            return s.substr(bestEvenStart, bestEvenLen);
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends