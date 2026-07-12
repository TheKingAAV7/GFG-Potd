class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // 6 4 4    6 5 4
        priority_queue<int>pq;
        int MOD=1e9+7;
        for(int &i:arr) pq.push(i);
        int ans=0;
        while(!pq.empty() and k){
            int cur= pq.top(); pq.pop();
            ans=(ans+cur)%MOD;
            cur--;
            if(cur>0)
            pq.push(cur);
            k--;
        }
        
        return ans;
        
        
    }
};