class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int x=it[2];
            int sz= r-l+2;
            auto lb= lower_bound(arr.begin()+l,arr.begin()+r+1,x);
            if(lb==(arr.begin()+r+1)){
                ans.push_back(0);
            }
            else{
                auto ub=upper_bound(arr.begin()+l,arr.begin()+r+1,x);
                ub--;
                int lefidx= lb-arr.begin();
               
                int rigidx= ub-arr.begin();
              //  cout<<lefidx<<" "<<l<<" "<<r<<" "<<rigidx<<endl;
                ans.push_back(max(0,rigidx-lefidx+1));
            }
        }
        return ans;
        
    }
};