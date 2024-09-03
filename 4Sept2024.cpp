//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



/*
Problem:
There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n = 4:- {1 2 1},{2 1 1},{1 1 2} are considered same.

Examples :

Input: n = 4
Output: 3
Explanation: Three ways to reach at 4th stair. They are {1, 1, 1, 1}, {1, 1, 2}, {2, 2}.
Input: n = 5
Output: 3
Explanation: Three ways to reach at 5th stair. They are {1, 1, 1, 1, 1}, {1, 1, 2, 1} and {1, 2, 2}.
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 ≤ n ≤ 104


*/



/*

***************************_SELF_************************


*/





class Solution{
	public:
		int nthStair(int n){
		    //  state -> no. of steps required to reach at ith state
		   /*
		   vector<int>dp(n+1,0);
		   dp[0]=0;
		   dp[1]=1;
		   dp[2]=2;
		   for(int i=3;i<=n;i++){
		       dp[i]=min(dp[i-1],dp[i-2])+1;
		   }
		   return dp[n];
		   
		   */
		   
		   if(n==1 || n==2) return n;  
		   int a=1;
		   int b=2;
		   int c;
		   for(int i=3;i<=n;i++){
		       c=min(a,b)+1;
		       a=b;
		       b=c;
		   }
		   return c;
		    
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
