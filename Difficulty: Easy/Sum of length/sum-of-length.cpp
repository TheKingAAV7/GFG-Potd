//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int sumoflength(vector<int>& arr) {
           unordered_map<int,int> mp;
           int mod=1e9+7;
            int n=arr.size();
        long long ans = 0;
        int j = 0;
        for(int i = 0; i < n;i++){
            while(j < n and mp.find(arr[j]) == mp.end()){
                    mp[arr[j]]++;
                    j++;
                }
                    ans = (ans%mod+ (((j-i)*(j-i+1))/2)%mod)%mod;
                    mp.erase(arr[i]); 
            }
        return ans%mod;

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
        Solution obj;
        int res = obj.sumoflength(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends