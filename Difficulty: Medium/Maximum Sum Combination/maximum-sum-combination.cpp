

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cstdint>
#include <iostream>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return (uint64_t(p.first) << 32) ^ uint64_t(p.second);
    }
};

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        unordered_map<pair<int,int>, int, pair_hash> mp;
        int n = a.size();
        vector<int> ans;

        priority_queue<vector<int>> pq;
        pq.push({ a.back() + b.back(), n-1, n-1 });
        mp[{n-1, n-1}] = 1;

        while (!pq.empty() && ans.size() < k) {
            auto it = pq.top(); pq.pop();
            ans.push_back(it[0]);
            int i = it[1], j = it[2];

            if (i > 0 && mp.find({i-1, j}) == mp.end()) {
                pq.push({ a[i-1] + b[j], i-1, j });
                mp[{i-1, j}] = 1;
            }

            if (j > 0 && mp.find({i, j-1}) == mp.end()) {
                pq.push({ a[i] + b[j-1], i, j-1 });
                mp[{i, j-1}] = 1;
            }
        }

        return ans;
    }
    

};
