class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
    int n = arr.size();
    sort (arr.begin(), arr.end());
    /*
 (1,4) (7,10) (10,15)
 (2,4)  (6,10) (9,12) 
 
 
  1 4
  10 15
  7 10
    
    */
    for (int i=0; i<n-1; i++) {
        if ( arr[i][1] > arr[i+1][0] ) {
            return false;
        }
        
    }
    return true;
    
    
    
    }
};