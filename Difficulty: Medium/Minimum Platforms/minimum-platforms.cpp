//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
       vector<pair<int,int>>v;
       int n=arr.size();
       int maxi=1;
       for(int i=0;i<n;i++){
       v.push_back({arr[i],dep[i]});
       maxi=max(dep[i],maxi);
       }
       vector<int>mp(maxi+1,0);
       sort(v.begin(),v.end());
       for(int i=0;i<n;i++){
           mp[v[i].first]+=1;
           if (v[i].second < maxi) 
             mp[v[i].second + 1] -= 1;

       }
       for(int i=1;i<=maxi;i++){
           mp[i]+=(mp[i-1]);
       }
       int ans=*max_element(mp.begin(),mp.end());
       
       return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends