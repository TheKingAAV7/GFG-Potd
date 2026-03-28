class Solution {
  public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans;
        vector<int> dp(n, -1);   // low
        vector<int> tim(n, -1);  // tin
        vector<int> ap(n, 0);    // articulation mark
        int ct = 0;

        function<void(int,int)> f = [&](int node, int strt) {
            tim[node] = dp[node] = ct++;
            int child = 0;

            for (auto it : adj[node]) {
                if (it == strt) continue;

                if (tim[it] == -1) {
                    child++;
                    f(it, node);
                    dp[node] = min(dp[node], dp[it]);

                    if (strt != -1 && dp[it] >= tim[node]) {
                        ap[node] = 1;
                    }
                } else {
                    dp[node] = min(dp[node], tim[it]);
                }
            }

            if (strt == -1 && child > 1) {
                ap[node] = 1;
            }
        };

        for (int i = 0; i < n; i++) {
            if (tim[i] == -1) f(i, -1);
        }

        for (int i = 0; i < n; i++) {
            if (ap[i]) ans.push_back(i);
        }

        if (ans.empty()) return {-1};
        return ans;
    }
};