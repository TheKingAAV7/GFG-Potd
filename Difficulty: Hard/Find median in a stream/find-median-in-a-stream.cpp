//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double>ans;
        multiset<int>s;
        auto it=s.begin();
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
            if(i==0) it=s.begin();
            else if(arr[i]>= *it and i%2==0) ++it;
            else if(arr[i]< *it and i%2==1) --it;
            if(i%2==0){
                ans.push_back((double(*it)));
            }
            else{
                auto nextit=next(it);
                ans.push_back((*it+*nextit)/2.0);
            }
        }
        return ans;
        }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends