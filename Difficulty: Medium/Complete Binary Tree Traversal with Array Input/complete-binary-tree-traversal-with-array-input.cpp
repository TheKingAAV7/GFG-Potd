class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n= arr.size();
        int pos=0;
        bool done=false;
        vector<vector<int>>ans;
        for(int i=1;;i*=2){
            pos=i-1;
            vector<int>tmp;
            for(int j=0;j<i;j++){
                if(pos+j>=n){
                    done=true;
                    break;
                }
                tmp.push_back(arr[pos+j]);
            }
            if(!tmp.empty())
            ans.push_back(tmp);
            if(done) break;
        }
        for(auto &it:ans){
            sort(it.begin(),it.end());
        }
        return ans;
        
        
    }
};
