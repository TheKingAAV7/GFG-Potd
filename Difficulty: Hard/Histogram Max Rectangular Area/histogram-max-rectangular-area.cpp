//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
     stack<pair<int,int>>st1,st2;
     int n=arr.size();
     vector<int>tmp(n,0);
     for(int i=0;i<n;i++){
         int cnt=1;
         while(!st1.empty() and st1.top().first>=arr[i]){
             cnt+=st1.top().second;
             st1.pop();
         }
         tmp[i]+=cnt;
         st1.push({arr[i],cnt});
     }
     for(int i=n-1;i>=0;i--){
         int cnt=1;
         while(!st2.empty() and st2.top().first>=arr[i]){
             cnt+=st2.top().second;
             st2.pop();
         }
         tmp[i]+=(cnt-1);
         st2.push({arr[i],cnt});
     }
     
     int ans=0;
     for(int i=0;i<n;i++){
         ans=max(ans,tmp[i]*arr[i]);
     }
     return ans;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends