class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        map<int,int>mp;
        for(auto i:arr) mp[i]++;
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b)->bool{
           if(a.second==b.second) return a.first>b.first;
           return a.second>b.second;
        });
        vector<int>ans;
        for(int i=0;i<min((int)v.size(),k);i++){
            ans.push_back(v[i].first);
        }
        return ans;
        
    }
};
