//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n=a.size(),m=b.size();
        
        if(n>m) return kthElement(b,a,k);
        int low=max(0,k-m), high=min(k,n);
        while(low<=high){
            int mid=(low+high)>>1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid-1>=0){
                l1=a[mid-1];
            }
            int pos=k-mid;
            if(pos-1>=0){
                l2=b[pos-1];
            }
            if(mid<n)
            r1=a[mid];
            if(pos<m)
            r2=b[pos];
            // cout<<l1<<" "<<r1<<endl;
            // cout<<l2<<" "<<r2<<endl;
            if(l1<=r2 and l2<=r1){
                return max(l1,l2);
            }
            if(l2>r1) low=mid+1;
            else high=mid-1;
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends