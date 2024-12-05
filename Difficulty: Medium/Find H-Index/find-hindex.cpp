//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& cit) {
        int n=cit.size();
        int ans=0;
       int low=0, high=n;
       auto f=[&](int k)->bool{
           int cnt=0;
           for(int i: cit){
               if(i>=k) cnt++;
           }
           return cnt>=k;
       };
       while(low<=high){
           int mid=(low+high)/2;
           if(f(mid)){
               ans=mid;
               low=mid+1;
           }
           else high=mid-1;
       }
       return ans;
       
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends