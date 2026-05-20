class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;
        
        return __builtin_popcount(n+1)==1;
        
    }
};