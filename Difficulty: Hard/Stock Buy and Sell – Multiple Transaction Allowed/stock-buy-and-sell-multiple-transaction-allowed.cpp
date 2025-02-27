//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &p) {
     int n=p.size();
     int mini=INT_MAX;
     int maxi=INT_MIN;
     int ans=0;
   
     for(int i=n-1;i>=0;i--){
         if(p[i]>mini){
         //   idx=i;
             ans+=(maxi-mini);
             mini=p[i];
             maxi=p[i];
         }
         else{
             mini=min(mini,p[i]);
             maxi=max(maxi,p[i]);
         }
     }

        ans+=(maxi-mini);
         
     
  
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends