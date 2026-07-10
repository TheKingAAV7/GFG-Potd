
class Solution {
  public:
    int getCount(int n) {
       
      int i=1;
      int sum=0;
      int ct=0;
      for(int j=1;j<n;j++){
        
          while(sum>n){
              sum-=i;
              i++;
          }
          if(sum==n){
              ct++;
          }
          sum+=j;
        
      }
      return ct;
     
    }
};