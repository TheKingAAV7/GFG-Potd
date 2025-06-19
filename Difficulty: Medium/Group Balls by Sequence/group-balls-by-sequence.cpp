class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        map<int,int>mp;
        for(auto it:arr) mp[it]++;
        
        if(n%k!=0) return false;
        
        for(int i=0;i<=1e5;i++){
            if(mp.find(i)!=mp.end()){
                while(mp.find(i)!=mp.end()){
                    int nxt=i+1;
                    int tmp=1;
                    while(tmp<k and mp.find(nxt)!=mp.end()){
                        mp[nxt]--;
                        if(mp[nxt]==0) mp.erase(nxt);
                        tmp++;
                        nxt++;
                    }
                    if(tmp<k) {
                       
                    return false;
                    }
                    
                    mp[i]--;
                    if(mp[i]==0) mp.erase(i);
                }
            }
        }
        return true;
    }
};