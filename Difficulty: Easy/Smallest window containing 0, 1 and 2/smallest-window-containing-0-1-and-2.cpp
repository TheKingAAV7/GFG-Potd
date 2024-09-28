//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int one=0, two=0, zero=0;
        int left=0;
        int ans=INT_MAX;
        int n=s.size();
        for(int right=0;right<n;right++){
            if(s[right]=='0') zero++;
            else if(s[right]=='1') one++;
            else two++;
            while(left<right and one>=1 and zero>=1 and two>=1){
                ans= min(ans, right-left+1);
                if(s[left]=='0') zero--;
                else if(s[left]=='1') one--;
                else two--;
                left++;
            }
            
        }
        if(ans==INT_MAX) return -1;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends