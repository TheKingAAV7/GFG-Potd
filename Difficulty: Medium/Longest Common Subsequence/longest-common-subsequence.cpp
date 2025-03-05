//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &s, string &t) {
       int n=s.length(),m=t.length();
       vector<vector<int>>dp(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(s[i]==t[j]){
                  if(i-1>=0 and j-1>=0) {
                      dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                  } 
                  else dp[i][j]=max(1,dp[i][j]);
               }
               if(i-1>=0){
                   dp[i][j]=max(dp[i][j],dp[i-1][j]);
               }
               if(j-1>=0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
           }
       }
       return dp[n-1][m-1];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends