class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int n= arr.size();
        int i=0,j=n-1;
        while((j-i+1)>1){
            if(arr[j]>=arr[i]){
                j--;
            }
            else i++;
        }
        // cout<<i<</" "<<j<<endl;
        return arr[i];
        
    }
};