class Solution {
  public:
    int mergeStones(vector<int> &stones, int K) {
        // code here
         
         
         /*
         
         Divide and Conquer?
         
         dp[i][j] represents minimum cost 
         
         HOW TO TRANSTION
         
         necessary 
         (j-i+1>=k)
            
            
        What happens after Merging some window..
        
        ok if(i-j+1==k) our answer is just the sum..
        
        else we can selct..
        
        // hint from CHATGPT
       
       Represent dp[i][j][k]
        Minimum cost to convert a window from i to j into k piles
        Transition
        
        dp[i][j][1]-> dp[i][j][1]
        
         */
         int n = stones.size();
        if ((n - 1) % (K - 1)) return -1;

        vector<int> prefix(n + 1);
        for (int i = 0; i <  n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<int> > dp(n, vector<int>(n));
        for (int m = K; m <= n; ++m)
            for (int i = 0; i + m <= n; ++i) {
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += K - 1)
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                if ((j - i) % (K - 1) == 0)
                    dp[i][j] += prefix[j + 1] - prefix[i];
            }
        return dp[0][n - 1];
    }
};