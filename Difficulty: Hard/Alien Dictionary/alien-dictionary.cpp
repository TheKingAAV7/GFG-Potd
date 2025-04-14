//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  bool dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor] && dfs1(neighbor, adj, visited, recStack))
            return true;
        else if (recStack[neighbor])
            return true;
    }

    recStack[node] = false;
    return false;
}

bool hasCycle( vector<vector<int>>& adj) {
    vector<bool> visited(26, false);
    vector<bool> recStack(26, false);

    for (int i = 0; i < 26; ++i) {
        if (!visited[i] && dfs1(i, adj, visited, recStack))
            return true;
    }

    return false;
}

  void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<char>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited, st);
    }
    st.push(char(node+'a'));
}

string f( vector<vector<int>>& adj,vector<int>&occ) {
    vector<bool> visited(26, false);
    stack<char> st;
    
    for (int i = 0; i < 26; ++i) {
        if(occ[i]==1){
        if (!visited[i])
            dfs(i, adj, visited, st);
        }
    }

    string topo="";
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
  
  public:
    string findOrder(vector<string> &words) {
        string tmp="";
        int sz=words.size();
        vector<int>occ(26,0);
        for(auto it:words){
            for(auto c:it) occ[c-'a']=1;
        }
        tmp=words[0];
        vector<vector<int>>adj(26);
        
        
        
        for(int i=1;i<sz;i++){
            
            int n=tmp.length();
            int m=words[i].length();
            
            int p1=0,p2=0;
            while(p1<n and p2<m){
                if(tmp[p1]==words[i][p2]){
                    p1++;
                    p2++;
                }
                else
                break;
                
            }
            // cout<<n<<" "<<m<<endl;
            // cout<<words[i]<<" "<<tmp<<endl;
            // cout<<i<<" "<<p1<<" "<<p2<<endl;
            if(p1==n and p2==m){
                tmp=words[i];
                continue;
            }
            if(p1<n and p2==m){
                return "";
            }
            if(p1==n and p2<m){
                tmp=words[i];
                continue;
            }
            adj[tmp[p1]-'a'].push_back(words[i][p2]-'a');
            tmp=words[i];
        }
        
        // for(int i=0;i<26;i++){
        //     if(occ[i]){
        //         cout<<char(i+'a')<<"->";
        //         for(auto c:adj[i]) cout<<char(c+'a')<<" ";
        //         cout<<endl;
        //     }
        // }
        if(hasCycle(adj)){
            return "";
        }
        
        return f(adj,occ);
        
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends