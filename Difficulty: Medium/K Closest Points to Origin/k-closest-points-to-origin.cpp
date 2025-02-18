//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b)->bool{
          double one = sqrt(pow(a[0],2.0)+pow(a[1],2.0));
          double two = sqrt(pow(b[0],2.0)+pow(b[1],2.0));
          return one<=two;
       });
       vector<vector<int>>ans;
       for(int i=0;i<k;i++){
           ans.push_back({points[i][0],points[i][1]});
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends