class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        /*
        
        
        1 2 4
        
        
        
        always check for smallest possible some, extend to the largest
        
        1 2 4
        
        1 2 3
        
    0   1 2 3 
        
         
        1 
        */
        sort(arr.begin(),arr.end());
        int lo=0,hi=0;
        
        int n= arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]-hi>1) return hi+1;
            
            hi=hi+arr[i];
            // cout<<hi<<endl;
        }
        return hi+1;
    }
};