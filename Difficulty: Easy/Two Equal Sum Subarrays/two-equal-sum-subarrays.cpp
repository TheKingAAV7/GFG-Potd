
#define ll long long
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        
        ll sm = accumulate(arr.begin(),arr.end(),0ll);
        ll csm=0;
        for(int i:arr){
          csm+=i;
          ll right= sm-csm;
          if(csm==right) return true;
        }
        return false;
        
        
    }
};
