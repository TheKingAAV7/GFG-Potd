//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        long long sm=0;
        
        unordered_map<long long,int>mp;
        int ans=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
           sm+=arr[i];
           if(mp.find(sm-k)!=mp.end()) ans=max(ans,i-mp[sm-k]);
           
           if(mp.find(sm)!=mp.end())
           mp[sm]=min(i,mp[sm]);
           else mp[sm]=i;
           
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends