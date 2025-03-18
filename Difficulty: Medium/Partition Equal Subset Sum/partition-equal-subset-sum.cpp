//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n=arr.size();
        int tsm=accumulate(arr.begin(),arr.end(),0);
        if(tsm%2!=0) return 0;
        int sum=tsm/2;
        vector<vector<int>>dp(sum+1,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=sum;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<n;j++){
                //ntake
                dp[i][j]|=dp[i][j-1];
                //take
                if(i-arr[j]>=0 ) dp[i][j]|=dp[i-arr[j]][j-1];
            }
        }
        return dp[sum][n-1];
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends