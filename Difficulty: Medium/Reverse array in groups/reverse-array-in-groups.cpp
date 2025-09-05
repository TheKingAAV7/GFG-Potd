class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
      int n=arr.size();
      int i=0;
      while(i<n){
          int lef=i;
          int rig=min(i+k-1,n-1);
          int post=rig;
          while(lef<rig){
              swap(arr[lef],arr[rig]);
              lef++;
              rig--;
          }
          i=post+1;
      }
      return ;
        
    }
};
