//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=2;k++){
                //buy -> buy now, buy later
                
                dp[i][k][1]= max(dp[i+1][k][0]-prices[i],dp[i+1][k][1]);
                //sell
                dp[i][k][0]=max(prices[i]+dp[i+1][k-1][1],dp[i+1][k][0]);
                
            }
        }
        return dp[0][2][1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends