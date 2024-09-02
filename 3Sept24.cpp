//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends




/*
PROBLEM:
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Examples :

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion.
p and h deleted from heap. Then, p is inserted at the beginning.
One thing to note, though p was required yet it was removed/deleted first from its position and then it is inserted to some other position. Thus, p contributes one to the deletion_count and one to the insertion_count.
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output: 8
Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ |str1|, |str2| ≤ 1000
All the characters are lowercase English alphabets




*******************************************************************************_SELF_****************************************************************************************

*/
class Solution{
		
    private: 
    int f(int i, int j, string str1, string str2, int m , int n,vector<vector<int>>&dp){
        
        if(i>=m ){
            return n-j;
        }
        if(j>=n){
            return m-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        
        if(str1[i]==str2[j]){
            return f(i+1,j+1, str1, str2, m, n,dp);
        }
        int remov=1+f(i+1,j, str1, str2, m, n,dp);
        int inser=1+f(i, j+1,str1, str2, m, n,dp);
        return  dp[i][j]=min(remov, inser);
        
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    vector<vector<int>>dp(str1.size(),vector<int>(str2.size(),-1));
	    
	   return  f(0,0,str1,str2,str1.size(),str2.size(),dp);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
