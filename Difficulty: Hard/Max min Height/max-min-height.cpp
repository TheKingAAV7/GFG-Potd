class Solution {
public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        int lo = *min_element(arr.begin(), arr.end());
        int hi = lo + k;              // bound the search
        int ans = lo;

        auto canReach = [&](int mid) {
            vector<long long> diff(n+1);
            long long used = 0, added = 0;
            for (int i = 0; i < n; ++i) {
                added += diff[i];
                long long curr = arr[i] + added;
                if (curr < mid) {
                    long long need = mid - curr;
                    used += need;
                    if (used > k) return false;
                    added += need;
                    // end effect after the w-length window
                    diff[min(n, i + w)] -= need;
                }
            }
            return true;
        };

        // binary search on [lo, hi]
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReach(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
