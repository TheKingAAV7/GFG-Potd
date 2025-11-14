class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<int> c;
        c.reserve(m + 2);
        c.push_back(0);
        for (int x : cuts) c.push_back(x);
        c.push_back(n);
        sort(c.begin(), c.end());
        int M = (int)c.size();
        vector<vector<int>> dp(M, vector<int>(M, 0));
        // length of interval grows from 2 (adjacent -> no cuts) upwards
        for (int len = 2; len < M; ++len) {             // len = j-i
            for (int i = 0; i + len < M; ++i) {
                int j = i + len;
                int best = INT_MAX;
                int cost_here = c[j] - c[i];
                for (int k = i + 1; k < j; ++k) {
                    int cur = cost_here + dp[i][k] + dp[k][j];
                    if (cur < best) best = cur;
                }
                dp[i][j] = (best == INT_MAX ? 0 : best);
            }
        }
        return dp[0][M-1];
    }
};
