//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
************_SOLVED_*********

*/
class Solution {
  public:
    void sort012(vector<int>& arr) {
       int low=0,mid=0,high= arr.size()-1;
       while(mid<=high){
           if(arr[mid]==0){
               swap(arr[mid],arr[low]);
               low++;
               mid++;
           }
           else if(arr[mid]==1){
               mid++;
           }
           else{
               swap(arr[mid],arr[high]);
               high--;
               
           }
       }
     
    }
};

// 1 0 1 2 0

//{ Driver Code Starts.



/*



************_Solved_****************
New approach:Deutch flag algorithm




*/
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends