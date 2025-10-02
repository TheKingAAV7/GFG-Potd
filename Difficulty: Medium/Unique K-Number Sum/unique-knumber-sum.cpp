class Solution {
  public:
    void f(int ele,int sm, vector<int>&tmp, int n ,int k, vector<vector<int>>&ans){
       if(tmp.size()==k ){
           if(sm==n){
               ans.push_back(tmp);
           }
           return;
       }
       if(ele>9) return ;
       f(ele+1,sm,tmp,n,k,ans);
       tmp.push_back(ele);
       f(ele+1,sm+ele,tmp,n,k,ans);
       tmp.pop_back();
       return ;
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>ans;
        vector<int>tmp;
        f(1,0,tmp,n,k,ans);
        return ans;
    }
};