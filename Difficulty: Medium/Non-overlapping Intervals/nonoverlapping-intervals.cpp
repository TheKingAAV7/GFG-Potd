//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &arr) {
         
     
 sort(arr.begin(), arr.end(), [&](vector<int>&a, vector<int>&b)->bool{
     return a[1]<b[1];
 });
       
        int maxi = arr[0][1];
     
   
       int ans = 0 ;
        for(int i = 1 ; i < arr.size();i++){
            int f = arr[i][0];
            int s = arr[i][1];
         
             
            if(maxi >  f) ans++;
            else {
                maxi = s;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends