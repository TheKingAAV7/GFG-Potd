//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




/*

Easy
******_SELF_SOLVED_******

Priority Queue 

*/
typedef long long ll;
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
       
        vector<ll>ans;
        ll tmp=0;
       priority_queue <ll, vector<ll>, greater<ll>> pq(arr.begin(),arr.end());
       
       while(pq.size()>=2){
           tmp=0;
           tmp+= pq.top();
           pq.pop();
           tmp+= pq.top();
           pq.pop();
           pq.push(tmp);
           ans.push_back(tmp);
       }
       tmp=0;
       for(ll i: ans) tmp+=i;
      
       return tmp;
       
       
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends
