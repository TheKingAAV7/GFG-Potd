//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        int n=arr.size();
      vector<vector<int>>dp(n,vector<int>(2,0));
    //   for(int i=0;i<n;i++){
    //       //dp[i][0]=arr[i];
    //       dp[i][1]=arr[i];
    //   }
      dp[0][1]=arr[0];
      
      if(n==1) return dp[0][1];
      dp[1][0]=arr[1];
      dp[1][1]=max(arr[1],arr[0]);
      for(int i=2;i<n;i++){
          dp[i][0]=max(dp[i][0],dp[i-1][0]);
          dp[i][0]=max(dp[i][0],arr[i]+dp[i-2][0]);
         
           
          if(i!=n-1){
              dp[i][1]=max(dp[i][1],dp[i-1][1]);
              dp[i][1]=max(dp[i][1],arr[i]+dp[i-2][1]);
          }
          else{
              dp[i][1]=max(dp[i][1],dp[i-1][1]);
          }
          
      }
    //   for(int i=0;i<n;i++){
    //       cout<<i<<"->";
    //       for(int j=0;j<2;j++) cout<<dp[i][j]<<" ";
    //       cout<<endl;
    //   }
      return max(dp[n-1][0],dp[n-1][1]);
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends