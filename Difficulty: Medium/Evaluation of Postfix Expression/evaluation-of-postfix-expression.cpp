//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]=="*" || arr[i]=="+" || arr[i]=="/" || arr[i]=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(arr[i]=="*"){
                    st.push(a*b);
                }
                else if(arr[i]=="+"){
                    st.push(a+b);
                }
                else if(arr[i]=="/") st.push(b/a);
                else st.push(b-a);
            }
            else{
                int neg=1;
                if(arr[i][0]=='-') neg=-1;
                int tmp=0;
                int pos=(neg==1)?0:1;
                for(int j=pos;j<arr[i].length();j++){
                    tmp=tmp*10+(arr[i][j]-'0');
                }
               // cout<<tmp<<endl;4
               tmp*=neg;
                st.push(tmp);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends