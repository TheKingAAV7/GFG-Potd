//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& s) {
       int n=s.length();
       vector<int>v(26,0);
       int cnt=0;
       for(auto c:s) {
      if(v[c-'a']==0){
       v[c-'a']=1;
       cnt++;
      }
       }
       int ans=n;
       
        
       map<char,int>mp;
       
       int l=0;
       for(int i=0;i<n;i++){
           if(v[s[i]-'a']){
               mp[s[i]]++;
           }
           while(mp.size()==cnt){
               ans=min(ans,i-l+1);
               if(v[s[l]-'a']){
                   mp[s[l]]--;
                   if(mp[s[l]]==0) mp.erase(s[l]);
               }
               l++;
             
           }
        
       }
          return ans;
        
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends