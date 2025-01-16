//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        
        vector<long long>suff(n,0),pref(n,0);
        long long prod=1;
        for(int i=0;i<n;i++){
            prod*=arr[i];
            pref[i]=prod;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=arr[i];
            suff[i]=prod;
        }
        vector<int>ans;
        ans.push_back(suff[1]);
        for(int i=1;i<n-1;i++){
            ans.push_back(pref[i-1]*suff[i+1]);
        }
        ans.push_back(pref[n-2]);
        return ans;
        
        
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends