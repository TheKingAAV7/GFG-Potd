//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find two elements such that their sum is equal to the given number
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
    int xor1 = 0;  // Will hold xor of all elements
                   // and numbers from 1 to n
    int set_bit_no;
    int x = 0, y = 0;

    // Get the xor of all array elements
    // And numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xor1 ^= arr[i];
        xor1 ^= (i + 1);  // 1 to n numbers
    }

    // Get the rightmost set bit in xor1
    set_bit_no = xor1 & ~(xor1 - 1);

    // Now divide elements into two sets 
    // by comparing rightmost set bit
    for (int i = 0; i < n; i++) {
      
        // Decide whether arr[i] is in first set 
        // or second
        if (arr[i] & set_bit_no)  { x ^= arr[i]; }  
        else                      { y ^= arr[i]; } 
      
        // Decide whether (i+1) is in first set 
        // or second
        if ((i+1) & set_bit_no)   { x ^= (i + 1); }
        else                      { y ^= (i + 1); }
    }
    
    
     int val = -1;
     
     for(int i = 0; i<n; i++){
         if(x==arr[i]){
             return {x,y};
         }
     }
    
            
        return {y, x};
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends