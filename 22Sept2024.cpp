//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

/*

Not_Solved
solution watched
*/

class Solution {
  public:
   int lps(string str) {
        // Your code goes here
        int n = str.length();
        vector<int> lps(n,0);
        int length = 0;
        int i = 1;
        
        while(i < n){
            if(str[i] == str[length]){
                length++;
                lps[i] = length;
                i++;
            }else{
                if(length != 0){
                    length = lps[length -1];
                }else {
                    lps[0] = 0;
                    i++;
                }
            }
        }
        return lps[n-1];
    }
};




//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends