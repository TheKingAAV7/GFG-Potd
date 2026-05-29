class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>v(n);
        v[n-1] = arr[n-2] ^ arr[n-1];
        for(int i=1;i<n-1;i++){
            v[i]=arr[i-1]^arr[i+1];
        }
        v[0] = arr[0] ^ arr[1];
        arr=v;
        return ;
        
    }
};