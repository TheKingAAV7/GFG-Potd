class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        int MAXn=1e5+1;
        int mp[MAXn];
        memset(mp,0,sizeof(mp));
        for(int &i:arr) mp[i]=1;
        vector<int>ans;
        for(int i=low;i<=high;i++){
            if(mp[i]==0) ans.push_back(i);
        }
        return ans;
        
    }
};