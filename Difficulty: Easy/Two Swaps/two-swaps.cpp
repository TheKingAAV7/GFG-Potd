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
        vector<int>vis(n+1,0);
        int element_to_look_for,ele;
        int ans=0;
        for(int i=0;i<n;i++){
           ele=arr[i];
           if(vis[ele]==0){
               vis[ele]=1;
               element_to_look_for=ele-1;
               while(vis[arr[element_to_look_for]]==0){
                   vis[arr[element_to_look_for]]=1;
                   element_to_look_for=arr[element_to_look_for]-1;
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