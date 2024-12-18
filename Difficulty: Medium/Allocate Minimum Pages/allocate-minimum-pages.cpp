//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
       // sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=-1;
        auto f=[&](int mid)->bool{
           int sm=0,cnt=1;
           
           for(int i=0;i<n;i++){
               if(sm+arr[i]<=mid){
                   sm+=arr[i];
               }
               else{
                cnt++;
                sm=arr[i];
                if(cnt>k) return false;
               }
           }
           //if(mid==90) cout<<cnt<<endl;
           return true;
               
      
           
           
   
        };
        
        while(low<=high){
            int mid=(low+high)/2;
            if(f(mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends