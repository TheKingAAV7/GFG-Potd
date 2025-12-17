class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        vector<int>od,ev;
        for(int i:arr){
            if(i&1) od.push_back(i);
            else ev.push_back(i);
        }
        sort(od.rbegin(),od.rend());
        sort(ev.begin(),ev.end());
        int pos=0;
        for(int i=0;i<od.size();i++){
            arr[pos++]=od[i];
        }
        
        for(int i=0;i<ev.size();i++) arr[pos++]=ev[i];
        return;
    }
};