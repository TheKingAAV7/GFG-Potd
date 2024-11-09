//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {   // 0 3 4 5 7        047   035
  public:
  //  0 4 7       35
    string minSum(vector<int> &arr) {
        sort(begin(arr),end(arr));
        int carry = 0, i, n = arr.size();
        string ans;
        
        for(i=n-1;i>=1;i-=2){
            int sum = arr[i]+arr[i-1]+carry;
            ans+=to_string(sum%10);
            carry=sum/10;
        }
        
        if(i == 0){
            int sum = arr[i]+carry;
            ans+=to_string(sum%10);
            carry=sum/10;
        }
        
        if(carry)ans+=to_string(carry);
        while(ans.back() == '0')ans.pop_back();
        
        reverse(begin(ans),end(ans));
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends