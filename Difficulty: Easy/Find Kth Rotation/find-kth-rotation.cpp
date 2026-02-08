class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        int n=arr.size();
        int mx=*max_element(arr.begin(),arr.end());
        for(int i=n-1;i>=0;i--){
            if(arr[i]==mx){
                return (1+i)%n;
            }
        }
        return 0;
        
    }
};
