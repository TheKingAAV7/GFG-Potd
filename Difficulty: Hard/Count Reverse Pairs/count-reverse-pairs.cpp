class Solution {
  private:
  int merge(int left , int right, int mid, vector<int>&arr){
      int n1 = mid - left + 1;
    int n2 = right - mid;
     
    int ans=0;
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++){
        
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        
        R[j] = arr[mid + 1 + j];
        auto it=upper_bound(L.begin(),L.end(),2*R[j]);
        ans+=(L.end()-it);
        
    }
    int i = 0, j = 0;
    int k = left;

    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
     
     return ans;
  }
  int mergesort(int l, int r, vector<int>&arr, int n){
      if(l>=r) return 0;
          int ans=0;
          int mid=(l+r)>>1;
          ans+=mergesort(l,mid,arr,n);
          ans+=mergesort(mid+1,r,arr,n);
          ans+=merge(l,r,mid,arr);
          return ans;
      
      //return 0;
  }
  public:
    int countRevPairs(vector<int> &arr) {
        int cnt=0;
        int n=arr.size();
        int ans=mergesort(0,n-1,arr,n);
        return ans;
        
    }
};