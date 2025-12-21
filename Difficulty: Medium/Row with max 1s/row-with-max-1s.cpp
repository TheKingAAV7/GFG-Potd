// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1;
        int cnt=-1;
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=0;j<m;j++){
                cur+=(arr[i][j]==1);
            }
            //cout<<cur<<endl;
            if(cur>=1){
                if(cur>cnt){
                    ans=i;
                    cnt=cur;
                }
            }
        }
        return ans;
        
    }
};