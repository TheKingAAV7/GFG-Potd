class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n=arr.size();
         auto it=lower_bound(arr.begin(),arr.end(),x);
         if(it!=arr.end()){
             if(*it==x){
                 auto it1=upper_bound(arr.begin(),arr.end(),x);
                 it1--;
                 int ans=it1-arr.begin();
                 return ans;
             }
         }
         if(it==arr.begin()) return -1;
         it--;
         if(*it<=x) {
              int ans=it-arr.begin();
                 return ans;
         }
         return -1;
        
    }
};
