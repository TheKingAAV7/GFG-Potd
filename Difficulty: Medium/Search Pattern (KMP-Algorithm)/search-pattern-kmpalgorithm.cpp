//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

vector<int> pf(string s) {
    int n =s.length();
    vector<int> p(n);
    for (int i = 1; i<n; i++) {
        int j = p[i-1];
        while (j > 0 and s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            string temp = pat + '?' + txt;
            vector<int> kmp = pf(temp);
            vector<int> ans;
            int start = 2 * pat.length();
            for(int i = start; i < temp.size(); i++){
                if(kmp[i] == pat.length())
                    ans.push_back(i - start + 1);
            }
            for(int &i: ans) i=i-1;

            return ans;
        }
     
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends