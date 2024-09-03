//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



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