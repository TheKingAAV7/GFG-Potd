//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // 2 4 1 7 5 2 0
        // 2 4 2 0 1 5 7
     //   2 4 1 7 5 2 2 0
        set<int>st;
        unordered_map<int, int>mp;
        int n= arr.size();
        int k=-1;
        for(int i=n-1;i>=0;i--){
            auto it=st.upper_bound(arr[i]);
            if(it==st.end()){
                st.insert(arr[i]);
                mp[arr[i]]=i;
            }
            else{
                swap(arr[i],arr[mp[*(it)]]);
                k=i;
                break;
            }
        }
        if(k==-1) sort(arr.begin(),arr.end());
        sort(arr.begin()+k+1,arr.end());
        return;
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends