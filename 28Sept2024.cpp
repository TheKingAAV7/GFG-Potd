//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*

Directly solved by tabulation... :)

*/
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=1;i<n;i++){
            // calculate dp[i]
            for(int j=1;j<=k;j++){
                if((i-j)>=0){
                 //  cout<<dp[i-j] <<" "<< abs(arr[i]-arr[i-j])<<endl;
                dp[i]= min(dp[i],dp[i-j] +  abs(arr[i]-arr[i-j]));
                }
            }
        }
        // cout<<"*************"<<endl;
        // for(int i: dp) cout<<i<<" ";
        // cout<<endl;
        return dp[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends