class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size();
        int tsm=0;
        for(int i=0;i<n;i++){
            tsm+=(gas[i]-cost[i]);
        }
        if(tsm<0) return -1;
        int idx=0,sm=0;
        for(int i=0;i<n;i++){
            sm+=(gas[i]-cost[i]);
            if(sm<0){
                sm=0;
                idx=i+1;
            }
        }
        return idx;
        
    }
};