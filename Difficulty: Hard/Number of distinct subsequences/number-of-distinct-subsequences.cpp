class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        /*
        
        So basically what we do is make dp[26]
        where dp[i] represents the no. of subsequences ending with 
        the letter i+'a'
        
        for the first letter add (sum-prev-1)0
        for the other letters , add  (sum-prev)
        */
        
        
        int n=str.length();
        
        int MOD=1e9+7;
        vector<int>dp(26,0);
        int first= (str[0]-'a');
        dp[first]=2;
        
        for(int i=1;i<n;i++){
            int sm=0;
            for(int j=0;j<26;j++) sm=(sm+dp[j])%MOD;
            
            if(str[i]==(first+'a')){
                dp[first]= (dp[first]+   (sm - (dp[first]-1) + MOD ))%MOD;
            }
            else{
                int cur= str[i]-'a';
                dp[cur]= (dp[cur] + (sm-dp[cur]) + MOD)%MOD;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans= (ans+ dp[i])%MOD;
        }
        
        return ans;
    }
};