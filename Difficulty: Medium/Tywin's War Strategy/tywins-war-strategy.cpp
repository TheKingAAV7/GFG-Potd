class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>v;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]%k==0) cnt++;
            else{
              int req= k-(arr[i]%k);
              v.push_back(req);
            }
        }
        sort(v.begin(),v.end());
        int pos=0;
        int ans=0;
        int reqcnt=ceil((1.0*n)/2.0);
        
        while(cnt<reqcnt){
            ans+=v[pos];
            pos++;
            cnt++;
        }
        return ans;
        
        
    }
};