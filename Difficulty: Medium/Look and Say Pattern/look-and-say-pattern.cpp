//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        string tmp="1";
        string ans="";
        for(int i=0;i<n-1;i++){
             ans="";
            int n1=tmp.length();
            int cnt=0;
            char c='-';
            for(int i=0;i<n1;i++){
                if(c=='-'){
                    cnt=1;
                    c=tmp[i];
                }
                else if(tmp[i]==c){
                    cnt++;
                }
                else{
                    ans+=to_string(cnt);
                    ans.push_back(c);
                    c=tmp[i];
                    cnt=1;
                }
                
            }
            ans+=to_string(cnt);
            ans.push_back(c);
            tmp=ans;
        }
        
      
            return tmp;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends