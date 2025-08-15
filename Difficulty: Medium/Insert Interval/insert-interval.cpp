class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &inter,
                                       vector<int> &newinter) {
        inter.push_back(newinter);
        sort(inter.begin(),inter.end());
        int n=inter.size();
        vector<vector<int>>ans;
        int mini=inter[0][0];
        int maxi=inter[0][1];
        for(int i=1;i<n;i++){
            int nl=inter[i][0];
            int nr=inter[i][1];
            if(nl>maxi){
                ans.push_back({mini,maxi});
                mini=nl;
                maxi=nr;
            }
            else{
                maxi=max(maxi,nr);
            }
        }
        ans.push_back({mini,maxi});
        return ans;
        
        
    }
};