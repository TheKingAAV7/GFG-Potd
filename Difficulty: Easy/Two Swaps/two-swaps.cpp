//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  void dfs(){
      
  }
  public:
    bool checkSorted(vector<int> &arr) {
        // 4 3 2 1 
        // 1 2 3 4
        
        // 4 3 1 2
        // 1 2 3 4
        int n=arr.size();
      //  vector<int>vis(n+1,0);
        int element_to_look_for;
        int ans=0;
        int tmp;
        for(int i=0;i<n;i++){
          
           if(arr[i]>0){
                tmp=arr[i]-1;
               arr[i]=0;
               element_to_look_for=tmp;
               while(arr[element_to_look_for]>0){
                   tmp=arr[element_to_look_for]-1;
                   arr[element_to_look_for]=0;
                   element_to_look_for=tmp;
                   ans++;
               }
               
           }
        }
        return ans==2 || ans==0;
        
    }
};
// 1 3 4 2
// 1 2 4 3
// 1 2 3 4
// 4 3 1 2
/*
4->0
3->1
1->2
2->3


*/



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends