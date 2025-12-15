class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n=arr.size();
        int total_od=0;
        int total_ev=0;
        for(int i=0;i<n;i++){
            if(i%2==0) total_ev+=arr[i];
            else total_od+=arr[i];
        }
        int cnt=0;
        int lef_od=0;
        int lef_ev=0;
        for(int i=0;i<n;i++){
            int rigod= total_od-lef_od;
            int rigev= total_ev-lef_ev;
            if(i%2==0) rigev-=arr[i];
            else rigod-=arr[i];
            if(lef_od+rigev== lef_ev+rigod) cnt++;
            
            if(i%2==0)
            lef_ev+=arr[i];
            else lef_od+=arr[i];
            
        }
        return cnt;
        
    }
};