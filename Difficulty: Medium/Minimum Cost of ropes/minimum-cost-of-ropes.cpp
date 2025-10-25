class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        /*
        Assumption :
        always choose first ttwo elements in a priority_queue
        because it can be possible that
        two small become, the new one of the top two smalls..
        
          6 9      5+9+15
        */
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i:arr) pq.push(i);
        int ans=0;
        while(pq.size()>=2){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            int nlen=top1+top2;
            ans+=nlen;
            pq.push(nlen);
        }
        return ans;
    }
};