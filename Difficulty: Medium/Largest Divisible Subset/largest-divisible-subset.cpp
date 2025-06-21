class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,1);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(arr[j]%arr[i]==0){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                
            }
        }
       
        vector<int>ans;
        int cnt=*max_element(dp.begin(),dp.end());
        int pos=0;
        
      //  cout<<cnt<<endl;
        for(int i=0;i<n;i++){
            if(dp[i]==cnt){
                pos=max(pos,i);
            }
        }
        ans.push_back(arr[pos]);
        cnt--;
        while(cnt>0){
            int maxi=pos,mxe=0;
            for(int i=pos;i<n;i++){
                if(dp[i]==cnt and arr[i]%arr[pos]==0){
                    maxi=max(maxi,i);
                }
            }
            ans.push_back(arr[maxi]);
            pos=maxi;
            cnt--;
        }
        return ans;
        
        
    }
};