//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int ele=-1;
        int cnt=0;
        for(int i:arr){
            if(ele==-1){
                ele=i;
                cnt=1;
            }
            else if(i==ele){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    ele=i;
                    cnt=1;
                }
            }
        }
        
        cnt=0;
        for(int i:arr){
            if(i==ele) cnt++;
        }
        
        if(cnt>(arr.size())/2) return ele;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends