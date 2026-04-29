class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n= arr.size();
        
        for(int i=0;i<n;i++){
            int left,right;
            left=right=INT_MIN;
            if(2*i+1<n){
                left= arr[2*i+1];
                // if(arr[i]>left) return false;
            }
            if(2*i+2<n){
                right= arr[2*i+2];
                // if(arr[i]>right) return false;
            }
            //  cout<<arr[i]<<" "<<left<<" "<<right<<endl;
            if(arr[i]<left || arr[i]<right) return false;
            
        }
        return true;
        
    }
};
