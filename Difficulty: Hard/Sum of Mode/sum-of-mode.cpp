class Solution {
    
  public:
  vector<int>st;
  
  int up(int idx, int lef, int rig, int i){
      if(lef==rig){
          st[i]++;
          return st[i];
      }
  }
    int sumOfModes(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=0;
        map<int,int>mp;
        map<int,set<int>>mp1;
        for(int i=0;i<k;i++){
            // add arr[i]
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=1;
                mp1[1].insert(arr[i]);
            }
            else{
            int prev_freq=mp[arr[i]];
            mp[arr[i]]++;
            mp1[prev_freq].erase(arr[i]);
            if(mp1[prev_freq].size()==0) mp1.erase(prev_freq);
            int new_freq=mp[arr[i]];
            mp1[new_freq].insert(arr[i]);
            }            
        }
        int max_freq=mp1.rbegin()->first;
        ans+=(*mp1[max_freq].begin());
        
        for(int i=k;i<n;i++){
            // remove i-k;
            int pidx=i-k;
            int prev_freq1=mp[arr[pidx]];
            mp[arr[pidx]]--;
            if(mp[arr[pidx]]==0) mp.erase(arr[pidx]);
            mp1[prev_freq1].erase(arr[pidx]);
            if(mp1[prev_freq1].size()==0) mp1.erase(prev_freq1);
            if(mp.find(arr[pidx])!=mp.end()){
                int new_freq=mp[arr[pidx]];
                mp1[new_freq].insert(arr[pidx]);
            }
            
            // add i
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=1;
                mp1[1].insert(arr[i]);
            }
            else{
            int prev_freq=mp[arr[i]];
            mp[arr[i]]++;
            mp1[prev_freq].erase(arr[i]);
            if(mp1[prev_freq].size()==0) mp1.erase(prev_freq);
            int new_freq=mp[arr[i]];
            mp1[new_freq].insert(arr[i]);
            }            
            
            int max_freq=mp1.rbegin()->first;
            ans+=(*mp1[max_freq].begin());
        }
        
        return ans;
    }
};