class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        priority_queue<array<int,3>>pq;
        int n=a.size();
        int m=b.size();
        for(int i=0;i<n;i++) pq.push({a[i],i,0});
        for(int i=0;i<m;i++) pq.push({b[i],i,1});
        int mx= max(a.back(),b.back());
        vector<int>dp(mx+1,0);
        while(!pq.empty()){
            auto cur= pq.top(); pq.pop();
            int val= cur[0];
            int idx= cur[1];
            int isb= cur[2];
            // if(val==1) cout<<isb<<endl;
            if(dp[val]==0) dp[val]=val;
            if(isb==0){
            if(idx+1<n)
            dp[val]= max(dp[val],val+dp[a[idx+1]]);
            }
            else{
             if(idx+1<m)
             dp[val]=max(dp[val],val+dp[b[idx+1]]);
            }
            
            // cout<<val<<" "<<isb<<" -> "<<dp[val]<<endl; 
        }
        // cout<<endl;
        
        
        // for(int i=0;i<=6;i++) cout<<i<<" -> "<<dp[i]<<endl;
        return max(dp[a[0]],dp[b[0]]);
    }
};