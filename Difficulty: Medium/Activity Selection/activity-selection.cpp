//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int,int>>v;
        int n=start.size();
        for(int i=0;i<n;i++) v.push_back({start[i],finish[i]});
        sort(v.begin(),v.end());
        vector<int>dp(n,0);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i],dp[i+1]);
            pair<int,int>p={v[i].second,INT_MAX};
            auto it=lower_bound(v.begin(),v.end(),p);
            if(it!=v.end()){
                int pos=(it-v.begin());
                //cout<<pos<<endl;
                dp[i]=max(dp[i],1+dp[pos]);
            }
        }
        return dp[0];
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends