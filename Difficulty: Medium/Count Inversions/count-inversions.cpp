//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int merge(vector<int>&arr,int lef, int mid, int rig){
    int res=0;
    int lefsz=mid-lef+1;
    int rigsz=rig-mid;
    vector<int>left(lefsz),right(rigsz);
    
    for(int i=0;i<lefsz;i++){
        left[i]=arr[lef+i];
    }
    for(int i=0;i<rigsz;i++){
        right[i]=arr[mid+i+1];
    }
    int i=0, j=0;
    int pos=lef;
    while(i<lefsz and j<rigsz){
        if(left[i]<=right[j]){
            arr[pos]=left[i];
            i++;
            pos++;
        }
        else{
            arr[pos]=right[j];
            j++;
            pos++;
            res+=(lefsz-i);
        }
    }
    
    while(i<lefsz){
        arr[pos]=left[i];
        pos++;
        i++;
    }
    while(j<rigsz){
        arr[pos]=right[j];
        pos++;
        j++;
    }
    return res;
}

int mergesort(vector<int>&arr, int lef, int rig){
    if(lef>=rig) return 0;
    int res=0;
    int mid=(lef+rig)/2;
    res+=mergesort(arr,lef,mid);
    res+=mergesort(arr,mid+1,rig);
    
    res+=merge(arr,lef,mid,rig);
    return res;
}

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        return mergesort(arr,0,n-1);
        
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends