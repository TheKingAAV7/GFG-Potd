class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here  
        vector<int>ans;
        int n=arr1.size();
        int m=arr2.size();
        int diff= INT_MAX;
        for(int i=0;i<n;i++){
            int req= x- arr1[i];
            auto it= lower_bound(arr2.begin(),arr2.end(),req);
            if(it!=arr2.end()){
                int sm1= *it+ arr1[i];
                if(abs(sm1-x)<diff){
                    diff= abs(sm1-x);
                    ans={arr1[i],*it};
                }
            }
            if(it!=arr2.begin()){
                it--;
                int sm1= *it+ arr1[i];
                if(abs(sm1-x)<diff){
                    diff= abs(sm1-x);
                    ans={arr1[i],*it};
                }
            }
            
        }
        return ans;
    }
};