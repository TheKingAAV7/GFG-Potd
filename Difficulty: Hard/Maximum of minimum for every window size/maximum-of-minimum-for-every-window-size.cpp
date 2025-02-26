//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n=arr.size();
        
        vector<int>ans(n,0);
        
        stack<pair<int,int>>st,st1;
        
        for(int i=0;i<n;i++){
            int cnt=1;
            
            while(!st.empty() and st.top().first>=arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            ans[i]+=cnt;
        }
        //  for(int i:ans) cout<<i<<" ";
        // cout<<endl;
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st1.empty() and st1.top().first>=arr[i]){
                cnt+=st1.top().second;
                st1.pop();
            }
            st1.push({arr[i],cnt});
            ans[i]+=(cnt-1);
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(ans[i])!=mp.end()){
                mp[ans[i]]=max(mp[ans[i]],arr[i]);
            }
            else mp[ans[i]]=arr[i];
        }
        int mini= *min_element(arr.begin(),arr.end());
        auto it=mp.rbegin();
        int sz=it->first;
        int maxi=it->second;
        
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        vector<int>res(n,mini);
        for(int i=sz;i>=0;i--){
            if(mp.find(i+1)!=mp.end()){
                maxi=max(maxi,mp[i+1]);
            }
                res[i]=max(res[i],maxi);
            
        }
        return res;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends