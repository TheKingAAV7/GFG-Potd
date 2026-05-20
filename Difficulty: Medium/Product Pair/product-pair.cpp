#define ll long long
class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // x*y= target
        int n= arr.size();
        map<ll,int>mp;
        for(int i=0;i<n;i++){
            ll x= arr[i];
            if(x==0){
                if(target==0ll){
                    if(mp.size()) return true;
                }
            }
            else{
            if(target%x!=0ll) continue;
            ll req= target/x;
            if(mp.find(req)!=mp.end()) return true;
            }
            mp[arr[i]]++;
        }
        return false;
        
        
        
    }
};