//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int req=0;
        int extra=0;
        int cur=0;
        int n=gas.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            cur+=gas[i];
            if(cur<cost[i]){
                req+=(cost[i]-cur);
                cur=0;
                idx=-1;
                
            }
            else{
                if(idx==-1){
                idx=i;
                }
                extra=(cur-cost[i]);
                cur-=cost[i];
            }
        }
      //  cout<<req<<" "<<extra<<endl;
        
        return extra>=req?idx:-1;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends