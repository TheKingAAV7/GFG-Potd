//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int cnt=0;
        unordered_map<char,int>mp;
        int n=s.length();
        int ans=1;
        for(int i=0,j=0;j<n;j++){
           
                mp[s[j]]++;
                cnt++;
            
            while(cnt>mp.size()){
                cnt--;
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            if(cnt==mp.size()) ans=max(ans,j-i+1);
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends