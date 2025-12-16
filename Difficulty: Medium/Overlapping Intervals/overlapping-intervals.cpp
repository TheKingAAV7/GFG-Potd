class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int lef= INT_MAX;
        int rig=INT_MIN;
        vector<vector<int>>ans;
        lef= arr[0][0];
        rig=arr[0][1];
        for(int i=1;i<n;i++){
            int curlef= arr[i][0];
            int currig= arr[i][1];
            if(curlef>rig){
                ans.push_back({lef,rig});
                lef=curlef;
                rig=currig;
            }
            else{
                rig=max(rig,currig);
            }
        }
        ans.push_back({lef,rig});
        return ans;
        
        
    }
};