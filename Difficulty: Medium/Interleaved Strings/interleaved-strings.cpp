class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        /*
        
        Obs:
        There are two ways to solve this I gues;;
        
        second one looks good
        
        
        dp[i][j][k] -> if we can construct s3 till k from s1 till i and s2 till j
        
        each time, we must choose one of the elements from s1 or s2
        
        if(s1[i]==s3[k]){
           dp[i][j][k]|= dp[i+1][j][k+1] 
        }
        if(s2[j]==s3[k]){
            dp[i][j][k]|= dp[i][j+1][k+1]
        }
        return dp[i][j][k]
        
        */
        
        int n=s1.length();
        int m=s2.length();
        int len= s3.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
    
    function<int(int , int , int)>f=[&](int i, int j, int k)->int{
        //if(i>=n and j>=m and k>=len) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=n){
            // s1 is over.., only left is s2
            while(j<m and k<len and s2[j]==s3[k]){
                j++;
                k++;
            }
            return dp[i][j] = (j>=m and k>=len);
        }
        
        if(j>=m){
            while(i<n and k<len and s1[i]==s3[k]){
                i++;
                k++;
            }
            return dp[i][j]= (i>=n and k>=len);
        }
        
        
        int ans=0;
        
        if(s1[i]==s3[k]){
            ans|= f(i+1,j,k+1);
        }
        if(s2[j]==s3[k]){
            ans|= f(i,j+1,k+1);
        }
        return dp[i][j]=ans;
      
    };
    
    return f(0,0,0);
        
        
    }
};