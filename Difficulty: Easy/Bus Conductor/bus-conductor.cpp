class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        int n=chairs.size();
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=abs(chairs[i]-passengers[i]);
        }
        return sm;
        
    }
};