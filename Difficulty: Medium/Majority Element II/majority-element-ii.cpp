//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
vector<int> findMajority(vector<int>& arr) {
    
        int ct1 = 0 , ct2 = 0 ;
        int el1 = INT_MIN , el2 = INT_MIN ;
        
        for(int i = 0 ; i < arr.size() ; i++){
                if(ct1 == 0 && arr[i] != el2){
                    ct1++ ;
                    el1 = arr[i] ;
                }else if(ct2 == 0 && arr[i] != el1){
                    ct2++ ;
                    el2 = arr[i] ;
                }else if(arr[i] == el1) ct1++ ;
                else if(arr[i] == el2) ct2++ ;
                else {
                    ct1-- ;
                    ct2-- ;
                }
        }
        
        int size = arr.size()/3 ;
        int x = 0 , y = 0 ;
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(el1 == arr[i])x++ ;
            else if(el2 == arr[i]) y++ ;
        }
        
        if(x > size && y > size){
            if(el1<el2) return {el1,el2};
            return {el2,el1};
        }
        
        if(x > size) return {el1};
        
        if(y > size) return {el2} ;
        
        return {} ;
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
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends