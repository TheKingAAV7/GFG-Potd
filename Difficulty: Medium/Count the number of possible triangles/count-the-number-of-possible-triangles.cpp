class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        // 0 4 28 33 38 45
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        int idx;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                
                if(arr[i]==0 || arr[j]==0) continue;
                int x=arr[i]+arr[j];
                auto it=lower_bound(arr.begin(),arr.end(),x);
                
                    
                    idx=it-arr.begin();
                    //cout<<i<<" "<<j<<" "<<idx<<endl;
                    ans+=(idx-j-1);
                
            }
        }
        return ans;
    }
};
