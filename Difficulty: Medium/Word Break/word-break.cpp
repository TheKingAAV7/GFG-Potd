//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int wordBreak(string &s, vector<string> &dict) {
        int n=s.length();
        int m=dict.size();
        vector<int>dp(n+1,0);
         unordered_set<string> dictSet(dict.begin(), dict.end());
        for(int i=n-1;i>=0;i--){
           for(int j=1;j<=100 and (i+j)<=n ; j++){
               string tmp=s.substr(i,j);
               if(dictSet.find(tmp)!=dictSet.end()){
                   if(i+j==n) dp[i]=1;
                   
                   else
                   dp[i]|=dp[i+j];
               }
           }
        }
        return dp[0];
        
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends