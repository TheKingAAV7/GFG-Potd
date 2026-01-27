class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        map<int,int>mp;
        int n=start.size();
        for(int i=0;i<n;i++){
            mp[start[i]]++;
            mp[end[i]]--;  // maybe mp[end[i]+1]--;
        }
        int sm=0;
        int mx=0;
        for(auto it:mp){
            sm+=it.second;
            mx=max(mx,sm);
        }
        return mx;
        
    }
};
