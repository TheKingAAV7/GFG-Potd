//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        if(str.size()==1){
            if(str[0]>='6') return "10";
            return "0";
        }
        if(str.back()=='0') return str;
       if(str.back()>='1' and str.back() <='5'){
           str.back()='0';
           return str;
       }
        
       str.back()='0';
       int pos=str.size()-2;
       while(pos>=0 and str[pos]=='9'){
           str[pos]='0';
           pos--;
       }
       if(pos<0) return "1" +str;
       str[pos]+=1;
       return str;
       
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends