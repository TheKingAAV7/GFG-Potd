//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        map<string,int>mp;
        vector<string>wds;
        for(auto it:words){
           
            if(mp.find(it)==mp.end()){
                 wds.push_back(it);
            mp[it]=1;
            }
            
        }
        sort(wds.begin(),wds.end(),[&](string &a, string &b)->bool{
           return a.length()<b.length(); 
        });
        // for(auto it:wds) cout<<it<<" ";
        // cout<<endl;
        int n=wds.size();
        for(int i=0;i<n;i++){
            int m=wds[i].length();
            int p=mp[wds[i]];
            
            for(int j=0;j<m;j++){
                string tmp=wds[i];
                tmp.erase(j,1);
               
                if(mp.find(tmp)!=mp.end()){
                     // if(wds[i]=="ji") cout<<".......... "<<tmp<<endl;
                    mp[wds[i]]=max(mp[wds[i]],mp[tmp]+p);
                }
            }
            }
            int maxi=1;
            for(auto it:mp){ 
                // cout<<it.first<<" "<<it.second<<endl;
            maxi=max(maxi,it.second);
            }
            return maxi;
        }
        
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends