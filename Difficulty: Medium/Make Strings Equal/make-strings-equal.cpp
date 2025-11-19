class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        int n= transform.size();
        
        vector<vector<int>>dp(26,vector<int>(26,INT_MAX));
        
        
        vector<vector<array<int,2>>>adj(26);
        
        for(int i=0;i<n;i++){
            auto it=transform[i];
            
            int cst= cost[i];
            adj[it[0]-'a'].push_back({it[1]-'a',cst});
        }
        
        
        for(int i=0;i<26;i++){
            dp[i][i]=0;
            // cost, character
            priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
            
            pq.push({0,i});
            
            while(!pq.empty()){
                auto cur= pq.top();
                pq.pop();
                
                int cst= cur[0];
                int chr= cur[1];
                
                if(dp[i][chr]!=cst) continue;
                
                for(auto it:adj[chr]){
                    int chr1= it[0];
                    int wt= it[1];
                    
                    int ncost= cst+wt;
                    if(ncost<dp[i][chr1]){
                        dp[i][chr1]=ncost;
                        pq.push({ncost,chr1}); 
                    }
                }
            }
        }
        
        
        // for(int i=3;i<=9;i++){
        //     for(int j=4;j<=10;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        
       
        
        int m=s.length();
        int ans=0;
       // set<pair<int,int>>st;
        for(int i=0;i<m;i++){
            int c1= s[i]-'a';
            int c2= t[i]-'a';
            if(c1==c2) continue;
        
            
            int tmp=INT_MAX;
            for(int j=0;j<26;j++){
            if(dp[c1][j]==INT_MAX || dp[c2][j]==INT_MAX) continue;
             tmp= min(dp[c1][j]+dp[c2][j],tmp);
            }
            if(tmp==INT_MAX) return -1;
            ans+=tmp;
            
        }
        
        // for(auto it:st){
        //     int c1= it.first;
        //     int c2= it.second;
            
        // }
        
      
        
        
        
        return ans;
    }
};