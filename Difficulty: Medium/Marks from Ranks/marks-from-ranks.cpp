class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        
        int n= l.size();
        vector<int>v;
        int prev=-1;
        for(int i=0;i<n;i++){
            int lef= max(l[i],prev+1);
            int rig= r[i];
            for(int j=lef;j<=rig;j++){
                v.push_back(j);
            }
        }
        vector<int>ans;
        for(int i:rank){
            ans.push_back(v[i-1]);
        }
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        return ans;
        
    }
};