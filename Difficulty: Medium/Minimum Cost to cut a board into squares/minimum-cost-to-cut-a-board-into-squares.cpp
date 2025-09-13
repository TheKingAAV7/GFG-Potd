class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        int v=1,h=1;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<m-1;i++) pq.push({x[i],'v'});
        for(int i=0;i<n-1;i++) pq.push({y[i],'h'});
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            //cout<<it.first<<" "<<it.second<<endl;
            if(it.second=='v'){
                ans+=(it.first*h);
                v++;
            }
            else{
                ans+=(it.first*v);
                h++;
            }
        }
        return ans;
    }
};
