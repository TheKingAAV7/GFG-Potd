class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& arr, int k) {
        // code here
        map<int,int>mp;
        for(auto it:arr){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int sm=0;
        int maxi=-1;
        for(auto it:mp){
            int cnt=it.second;
            if(sm>=k) maxi=max(maxi,it.first-1);
            sm+=it.second;
            if(sm>=k) maxi=max(maxi,it.first);
            
        }
        return maxi;
        
    }
};