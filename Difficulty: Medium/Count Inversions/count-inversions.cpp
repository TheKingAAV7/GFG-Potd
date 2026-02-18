
class FenwickTree{
  public:
  vector<int>bit;
  int n;
  FenwickTree(int n){
      this->n=n;
      bit.resize(n,0);
      // t(i) = answer for [g(i),i]
        //                    [g(g(i-1)),g(i-1)]
  }
  void increase(int idx, int val){
      for(;idx<n;idx= idx|(idx+1)){
          bit[idx]+=val;
      }
      
  }
  int sum(int r){
      int sm=0;
      while(r>=0){
          sm+=bit[r];
          r=(r&(r+1))-1;
      }
      return sm;
  }
  
  int query(int l, int r){
      return sum(r)-sum(l-1);
  }
};
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int MAXI=1e4+1;
        FenwickTree ft= FenwickTree(MAXI);
        // count the bigger on the left
        
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt= ft.query(arr[i]+1,1e4);
            ans+=cnt;
            ft.increase(arr[i],1);
            
        }
        return ans;
    }
};