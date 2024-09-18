//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*


*************_Solved_*************
Easy


*/

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        string ans="";
        string tmp="";
        for(char c: str){
            if(c=='.'){
                ans = "." + tmp+ans;
                tmp="";
            }
            else tmp+=c;
        }
        //ans.erase(0, 1);
        ans=tmp+ans;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
