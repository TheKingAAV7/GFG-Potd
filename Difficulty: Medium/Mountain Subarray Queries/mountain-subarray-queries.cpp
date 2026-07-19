class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n= arr.size();
        vector<int>pref(n,0),suff(n,0);
        int prev=INT_MAX;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
           if(arr[i]<=prev) cnt++;
           else cnt=1;
           prev=arr[i];
           pref[i]=cnt;
        }
        prev=-1;
        
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=prev) cnt++;
            else cnt=1;
            prev=arr[i];
            suff[i]=cnt;
        }
        
        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;
        // for(int i:suff) cout<<i<<" ";
        // cout<<endl;
        vector<bool>ans;
        for(auto &it:queries){
            int lef= it[0];
            int rig= it[1];
            int sz= rig-lef+1;
            if(pref[lef]>=sz || (suff[lef]>=sz)) {
                ans.push_back(true);
                continue;
            } 
            int left= pref[lef];
            int tocheck= lef+left;
            int right=suff[tocheck];
            int rsz=sz-left;
            if(right>=rsz) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
        
    }
};