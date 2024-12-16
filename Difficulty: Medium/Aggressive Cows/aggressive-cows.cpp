//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &st, int k) {
        sort(st.begin(),st.end());
        int low=1,high=(st.back()-st[0]);
        int ans=0;
        
        auto f=[&](int mid)->bool{
            int tmp=k-1;
            int left=st[0];
            int reqNo;
            while(tmp--){
                reqNo=left+mid;
                auto it=lower_bound(st.begin(),st.end(),reqNo);
                if(it==st.end()){
                    return false;
                }
                left= (*(it));
            }
            return true;
        };
        while(low<=high){
            int mid=(low+high)>>1;
            if(f(mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends