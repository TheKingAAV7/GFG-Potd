class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        sort(pts.begin(),pts.end(),[&](vector<int>&a,vector<int>&b)->bool{
            int dist1=pow(a[0],2)+ pow(a[1],2);
            int dist2=pow(b[0],2)+ pow(b[1],2);
            return dist1<dist2;
        });
        vector<vector<int>>ans;
        for(int i=0;i<k;i++) ans.push_back(pts[i]);
        return ans;
        
    }
};