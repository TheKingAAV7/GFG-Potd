//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
       int l=0, h=arr.size()-1;
       int n=arr.size();
       while(l<=h){
           int mid=(l+h)>>1;
           int x=INT_MIN,y=arr[mid],z=INT_MAX;
           if(mid-1>=0){
               x=arr[mid-1];
           }
           if(mid+1<n) z=arr[mid+1];
           
           if(x==target) return mid-1;
           if(y==target) return mid;
           if(z==target) return mid+1;
           
           if(arr[mid]>target){
               h=mid-1;
           }
           else l=mid+1;
           
       }
       return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends