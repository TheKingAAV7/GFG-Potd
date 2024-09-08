//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array


/*

Not Solved but the intuition was right

*************_Not Solved_*************



*/
class Solution {
    public:
     int minJumps(vector<int>&arr ) {
        int n = arr.size();
        int jumps = 0;
        int l = 0, r = 0;
        
        while(r < n-1)
        {
            int far = 0;
            for(int i = l;i <= r;i++)
                far = max(far, i + arr[i]);
                
            if(far == r)
                return -1;
                
            l = r+1;
            r = far;
            jumps++;
        }
        return jumps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends