//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   private: 
//   int f(int i, int j, string &str1, string &str2, int m, int n,vector<vector<int>>&dp){
//      if(i>=m) return n-j;
//      if(j>=n) return m-i;
//      if(dp[i][j]!=-1) return dp[i][j];
        
//      if(str1[i]==str2[j]){
//          return f(i+1,j+1,str1,str2,m,n,dp);
//      }
//      int insert=1+f(i,j+1,str1,str2,m,n,dp);
//      int removes= 1+f(i+1,j,str1,str2,m,n,dp);
//      int replace= 1+ f(i+1,j+1,str1,str2,m, n,dp);
//      return dp[i][j]= min(insert, min(removes, replace));
//   }
//   public:
//     int editDistance(string str1, string str2) {
//       int size=max(str1.size(),str2.size());
//       vector<vector<int>>dp(str1.size(),vector<int>(str2.size(),-1));
//      int lcs= f(0,0,str1,str2,str1.size(),str2.size(),dp);
//      //cout<<str1.size()<<str2.size()<<lcs<<endl;
//       return lcs;
//     }
// };
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s, string& t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e7));
        for(int j=0;j<=m;j++){
            dp[n][j]=m-j;
        }
        for(int i=0;i<=n;i++) dp[i][m]=n-i;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    
                    dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
                    
                }
                else{
         
                   dp[i][j]=min(1+dp[i][j+1],dp[i][j]);
                   
                   
                   
                   
                   dp[i][j]=min(1+dp[i+1][j],dp[i][j]);
                   
                   
                   
                   
                
                   dp[i][j]=min(1+dp[i+1][j+1],dp[i][j]);
                
                   
                   
                   
                   
                }
                //insert  dp[i][j]=min(1+dp[i][j+1],dp[i][j]);
                //remove dp[i][j]=min(1+dp[i+1][j],dp[i][j]);
                //replace dp[i][j]=min(1+dp[i+1][j+1],dp[i][j]);
                //skip dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
            }
           
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends