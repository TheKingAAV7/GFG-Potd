//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */


int countPairsWithDiffK(vector<int>& arr, int k) {
    int ans = 0;
    unordered_map<int, int> mp;

    // Fill frequency map
    for (int num : arr) {
        mp[num]++;
    }

    unordered_set<int> vis;
    for (int num : arr) {
        // Check for pairs only if the number hasn't been visited
        if (vis.find(num) == vis.end()) {
            vis.insert(num);  // Mark the current number as visited

            // Check if pair with difference `+k` exists
            if (mp.find(num + k) != mp.end()) {
                ans += mp[num] * mp[num + k];
            }

            // Check if pair with difference `-k` exists
            if (mp.find(num - k) != mp.end()) {
                ans += mp[num] * mp[num - k];
            }
        }
    }

    return ans / 2;  // Divide by 2 to avoid double-counting pairs
}

};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends