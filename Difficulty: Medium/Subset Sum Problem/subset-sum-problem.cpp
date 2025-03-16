//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>>dp(sum+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<n;i++){
            if(arr[0]<=sum)
            dp[arr[0]][i]=1;
        }
        for(int i=1;i<=sum;i++){
            
        for(int j=1;j<n;j++){
            if(i-arr[j]>=0 and j-1>=0){
                dp[i][j]|= (dp[i-arr[j]][j-1] );
                
            }
            if(j-1>=0) dp[i][j]|=dp[i][j-1];
        }
        
        }
        // for(int i=0;i<=sum;i++){
        //     for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends