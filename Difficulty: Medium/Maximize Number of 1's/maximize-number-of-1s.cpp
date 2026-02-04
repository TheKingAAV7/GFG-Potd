class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=0;
        int cost=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cost++;
            }
            while(cost>k){
                if(arr[l]==0) cost--;
                l++;
            }
            mx=max(mx,i-l+1);
        }
        return mx;
    }
};
