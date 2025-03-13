//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int i=0;i<n;i++){
            for(int w=1;w<=W;w++){
                //take
                if(w-wt[i]>=0){
                if(i-1>=0)
                dp[i][w]=max(dp[i][w],val[i]+dp[i-1][w-wt[i]]);
                else dp[i][w]=val[i];
                }
                //ntake
                if(i-1>=0)
                dp[i][w]=max(dp[i][w],dp[i-1][w]);
                
            }
        }
        return dp[n-1][W];
        
        
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends