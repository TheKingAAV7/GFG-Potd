class Solution {
  public:
    long long maxScore(string &s, vector<vector<char>> &jumps) {
        int n= s.length();
// COpied..
        vector<vector<int>> cango(26,vector<int>(26,0));
        for(int i=0;i<26;i++){
            cango[i][i]=1;
        }
        for(const auto &it : jumps){
            int a= it[0]-'a';
            int b= it[1]-'a';
            cango[a][b]=1;
        }

        // build adjacency lists (so we don't always loop 0..25)
        vector<vector<int>> adj(26);
        for(int a=0;a<26;a++){
            for(int b=0;b<26;b++){
                if(cango[a][b]) adj[a].push_back(b);
            }
        }

        vector<vector<int>> pref(n,vector<int>(26,0));
        vector<int> pos(26,-1);
        vector<int> mp(26,0);
        // prefix ascii sums (inclusive)
        vector<long long> asciiPref(n,0);

        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
            pref[i]= mp;
            long long val = (int)s[i];
            asciiPref[i] = val + (i? asciiPref[i-1] : 0LL);
        }

        vector<long long> dp(n+1,0); // use long long for safety

        for(int i=n-1;i>=0;i--){
            int cur = s[i]-'a';
            // iterate only over allowed jumps from cur
            for(int j : adj[cur]){
                if(pos[j] != -1){
                    int posi = pos[j];
                    // count of char j in range [i..posi] (inclusive)
                    int cnt_j = pref[posi][j] - (i==0 ? 0 : pref[i-1][j]);
                    // total ascii sum in range [i..posi] inclusive
                    long long rangeAscii = asciiPref[posi] - (i==0 ? 0LL : asciiPref[i-1]);
                    // sum excluding characters equal to j
                    long long tsm = rangeAscii - 1LL * cnt_j * ( (int)('a') + j );
                    dp[i] = max(dp[i], tsm + dp[posi]);
                }
            }
            pos[cur]=i;
        }

        return dp[0];
    }
};
