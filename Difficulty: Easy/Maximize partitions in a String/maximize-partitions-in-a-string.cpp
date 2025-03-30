//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        vector<int>v(26,INT_MAX);
        int cnt=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(v[s[i]-'a']==INT_MAX){
                v[s[i]-'a']=i;
            }
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(maxi==-1){
                maxi=v[s[i]-'a'];
            }
            
            if(maxi==i){
                cnt++;
                maxi=-1;
            }
            else{
                maxi=max(v[s[i]-'a'],maxi);
            }
        }
        return cnt;
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends