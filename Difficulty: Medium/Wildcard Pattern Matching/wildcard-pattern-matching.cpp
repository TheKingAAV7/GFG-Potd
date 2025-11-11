class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        bool tmp=false;
        while(pat.back()=='*'){
            tmp=true;
        pat.pop_back();
        }
        if(tmp) pat.push_back('*');
        int n=txt.length();
        int m=pat.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        function<int(int, int)>f=[&](int i, int j)->int{
            
            if(i==n and j==m) return 1;
            if(i==n and (j==m-1 and pat[j]=='*')) return 1;
            if(i>=n || j>=m) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            
            int ans=0;
            if(txt[i]==pat[j]){
                
                ans |= f(i+1,j+1);
            }
            else{
                if(pat[j]=='?') ans|=f(i+1,j+1);
                if(pat[j]=='*'){
                    for(int idx=i;idx<=n;idx++)
                    ans|=f(idx,j+1);
                }
            }
            
            
            return dp[i][j]=ans;            
            
        };
        
        return f(0,0);
        
        
        /*
        
        dp[i][j] -> if we can match the strings txt upto i and pat upto j
        if(s[i]==t[j]){
            dp[i][j] |= (dp[i+1][j+1])
        }
        else{
            if(pat[j]=='?') dp[i][j] |= dp[i+1][j+1]
            if(pat[j]=='*'){
                for(int idx=i;idx<n;idx++){
                    dp[i][j]|= dp[idx][j+1]
                }
            }
            
        }
        
        */
    }
};