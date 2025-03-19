//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    int dp[1001][201][2];
    int solve(int idx,int k,bool canbuy,vector<int> &prices) {
        if(k == 0 || idx >= n) return 0;
        
        int result = INT_MIN;
        
        if(dp[idx][k][canbuy] != -1) 
          return dp[idx][k][canbuy];
        
        if(canbuy) {
            int buy = solve(idx+1,k,false,prices) - prices[idx];
            int not_buy = solve(idx+1,k,true,prices);
            
            result = max({buy,not_buy});
        }
        else{
            int sell =  prices[idx] + solve(idx+1,k-1,true,prices);
            int not_sell = solve(idx+1,k,false,prices);
            result = max({sell,not_sell});
        }
        return dp[idx][k][canbuy] = result;
    }
    int maxProfit(vector<int>& prices, int k) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,k,true,prices);
    }
};

//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends