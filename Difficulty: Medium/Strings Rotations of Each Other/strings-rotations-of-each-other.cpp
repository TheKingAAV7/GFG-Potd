class Solution {
public:
    bool areRotations(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;

        string ss = s1 + s1;                
        string res = s2 + '#' + ss;          
        int n = res.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;

        int req = (int)s2.size();
        for (int i = 1; i < n; ++i) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && res[z[i]] == res[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
            if (z[i] == req) return true;
        }
        return false;
    }
};
