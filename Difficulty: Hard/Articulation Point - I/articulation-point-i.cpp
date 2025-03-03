//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
private:
    // DFS function to compute discovery and low times.
    // 'time' is passed by reference so that it increases globally.
    void dfs(int node, int parent, vector<int>& vis, vector<pair<int,int>>& tim, vector<int> adj[], int &time, set<int>& ap) {
        vis[node] = 1;
        // Initialize discovery and low times
        tim[node].first = tim[node].second = time++;
        int children = 0;  // count children in DFS tree
        
        for (int it : adj[node]) {
            if (!vis[it]) {
                children++;
                dfs(it, node, vis, tim, adj, time, ap);
                // Update low value of current node based on child's low value
                tim[node].second = min(tim[node].second, tim[it].second);
                
                // If not root and child's low time is not before node's discovery time,
                // then node is an articulation point.
                if (parent != -1 && tim[it].second >= tim[node].first)
                    ap.insert(node);
            }
            // Update low time if there is a back edge (and not direct parent)
            else if (it != parent) {
                tim[node].second = min(tim[node].second, tim[it].first);
            }
        }
        // Special case: if root node has more than one child, it's an articulation point.
        if (parent == -1 && children > 1)
            ap.insert(node);
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        // Each pair: first = discovery time, second = low value.
        vector<pair<int,int>> tim(n, {0, 0});
        set<int> ap;
        int time = 0;
        dfs(0,-1,vis,tim,adj,time,ap);
        // Run DFS from all nodes to cover disconnected components.
       
        
        vector<int> ans;
        if (ap.empty()) {
            ans.push_back(-1);
            return ans;
        }
        for (int point : ap)
            ans.push_back(point);
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends