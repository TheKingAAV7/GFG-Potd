//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


/*
Problem :
Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  
Examples :

Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
Expected Time Complexity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 500



*/



/*


******************************************************************************_SELF_ **************************************************************************************


*/

typedef pair<int, pair<int, int>> pii;

class Solution
{
    
    private: 
    int f(vector<vector<int>>&grid,int n){
          vector<vector<int>>vis(n, vector<int>(n,0));
          priority_queue<pii, vector<pii>, greater<pii> > q;
          q.push({grid[0][0],{0,0}});
          vis[0][0]=1;
          
          while(!q.empty()){
              int val= q.top().first;
              int i=q.top().second.first;
              int j= q.top().second. second;
              q.pop();
              if(i==n-1 and j==n-1){
                return val;
              }
              
              //up i-1
              if(i-1>=0 and j>=0 and j<n and (i-1)<n and vis[i-1][j]==0){
                vis[i-1][j]=1;
                q.push({val+grid[i-1][j],{i-1,j}});
                  
              }
              //down
              if(i+1>=0 and j>=0 and j<n and (i+1)<n and vis[i+1][j]==0){
                vis[i+1][j]=1;
                q.push({val+grid[i+1][j],{i+1,j}});
                  
              }
              // right
              if(i>=0 and j+1>=0 and (j+1)<n and (i)<n and vis[i][j+1]==0){
                vis[i][j+1]=1;
                q.push({val+grid[i][j+1],{i,j+1}});
                  
              }
              
              //left
              
              if(i>=0 and j-1>=0 and (j-1)<n and (i)<n and vis[i][j-1]==0){
                vis[i][j-1]=1;
                q.push({val+grid[i][j-1],{i,j-1}});
                  
              }
              
              
              
          }
          return 0;
          
       

        
    }
    public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {   
        int n= grid.size();
      
        return f(grid,n);
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
