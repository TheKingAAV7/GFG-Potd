//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &digits) {
        int n=digits.size();
        if(n==1) return digits[0]!='0';
        vector<int>dp(n+1,0);
        if(digits.back()=='0')dp[n-1]=0;
        else dp[n-1]=1;
        int tmp=(digits[n-2]-'0')*10+(digits[n-1]-'0');
        
        if(digits[n-2]!='0') dp[n-2]=dp[n-1];
        if(tmp>=10 and tmp<=26) dp[n-2]+=1;
        
        for(int i=n-3;i>=0;i--){
            //int f=0;
            int one=0,tww=0;
            
            string two=digits.substr(i,2);
            if(digits[i]!='0'){ 
              if(dp[i+1]!=0)  
            one=dp[i+1];
            }
            int tmp=(two[0]-'0')*10 + (two[1]-'0');
          
            if(tmp>=10 and tmp<=26){
                if(dp[i+2]!=0)
                 tww=dp[i+2];
            }
            //cout<<one<<" "<<tww<<endl;
            dp[i]=(one+tww);
            
            
            
        }
        return dp[0];
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends