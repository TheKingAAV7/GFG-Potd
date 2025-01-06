//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
       int diff=INT_MAX;
       sort(arr.begin(),arr.end());
       vector<int>ans(2,1);
       int n=arr.size();
        if(n==1) return {};
        int i=0,j=n-1;
        while(i<j){
            int sm= abs(target - (arr[i]+arr[j]));
            if(sm<diff){
                ans[0]=arr[i];
                ans[1]=arr[j];
                diff=sm;
            }
            
            if(arr[i]+arr[j]>target){
                j--;
            }
            else i++;
            
        }
        sort(ans.begin(),ans.end());
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends