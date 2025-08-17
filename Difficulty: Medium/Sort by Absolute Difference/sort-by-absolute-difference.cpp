class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        int n=arr.size();
     vector<vector<int>>v;
     for(int i=0;i<n;i++){
         v.push_back({arr[i],i});
     }
      
      sort(v.begin(),v.end(),[&](vector<int>& a, vector<int>& b)->bool{
          if(abs(x-a[0])==abs(x-b[0])) return a[1]<b[1];
          return abs(x-a[0])<abs(x-b[0]);
      });
      for(int i=0;i<n;i++){
          arr[i]=v[i][0];
      }
      return ;
        
    }
};