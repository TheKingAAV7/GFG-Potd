class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> prefix(n+1, 0);
        
        // build prefix sum
        for (int i = 0; i < n; ++i)
            prefix[i+1] = prefix[i] + arr[i];

        long long ans = LLONG_MAX;

        for (int l = 0; l < n; ++l) {
            int limit = arr[l] + k;
            int m = lower_bound(arr.begin(), arr.end(), limit + 1) - arr.begin();

            long long cost_left = prefix[l];
            long long cost_right = prefix[n] - prefix[m] - 1LL * (n - m) * limit;

            long long total_cost = cost_left + cost_right;
            ans = min(ans, total_cost);
        }

        return (int)ans;
    }
};
