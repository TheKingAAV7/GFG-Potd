class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        int MOD=1000;
        queue<int>q;
        q.push(start);
        vector<int>vis(1001,INT_MAX);
        vis[start]=0;
        while(!q.empty()){
            auto x= q.front();q.pop();
            if(x==end) return vis[x];
            for(int i:arr){
                int nval= (x*i)%MOD;
                if(vis[nval]==INT_MAX){
                    vis[nval]=1+vis[x];
                    q.push(nval);
                }
            }
        }
        return -1;
        /*
        
        start,
        
        */
        
    }
};