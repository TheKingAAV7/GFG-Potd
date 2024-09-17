//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*



*************_SOlved_*************


*/

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>st;
        for(char c: x){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                if(c==')' and st.top()=='(')st.pop();
                else if(c==']' and st.top()=='[')st.pop();
                else if(c=='}' and st.top()=='{') st.pop();
                else return false;
            }
            
        }
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends