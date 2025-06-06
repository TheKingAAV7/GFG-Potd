#define ll long long
class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int n = pat.length();
        int m = txt.length();
        vector<int> ans;
        ll p = 31;
        int mod = 1e9 + 7;
        auto modexp = [&](ll b, ll e) {
            ll r = 1;
            while (e) {
                if (e & 1) r = (r * b) % mod;
                b = (b * b) % mod;
                e >>= 1;
            }
            return r;
        };
        ll invP = modexp(p, mod - 2);
        ll hash = 0, hash1 = 0, po = 1;
        for (int i = 0; i < n; i++) {
            hash = (hash + (pat[i] - 'a' + 1) * po % mod) % mod;
            hash1 = (hash1 + (txt[i] - 'a' + 1) * po % mod) % mod;
            if (i != n - 1) po = (po * p) % mod;
        }
        if (hash == hash1) ans.push_back(1);
        for (int i = n; i < m; i++) {
            hash1 = (hash1 - (txt[i - n] - 'a' + 1) + mod) % mod;
            hash1 = (hash1 * invP) % mod;
            hash1 = (hash1 + (txt[i] - 'a' + 1) * po % mod) % mod;
            if (hash1 == hash) ans.push_back(i - n + 2);
        }
        return ans;
    }
};
