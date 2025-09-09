class Solution {
  public:
    int assignHole(vector<int>& mo, vector<int>& ho) {
        // code here
        sort(mo.begin(),mo.end());
        sort(ho.begin(),ho.end());
        int ans=0;
        for(int i=0;i<mo.size();i++)
        ans=max(ans,abs(mo[i]-ho[i]));
        return ans;
        
    }
};