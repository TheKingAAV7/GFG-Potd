class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n=arr.size();
       // cout<<n<<endl;
        vector<int>v(n,0);
        stack<array<int,2>>st,st1;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st.empty() and arr[i]>=st.top()[0]){
                cnt+=st.top()[1];
                st.pop();
            }
            st.push({arr[i],cnt});
            v[i]=cnt;
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st1.empty() and arr[i]>=st1.top()[0]){
                cnt+=st1.top()[1];
                st1.pop();
            }
            st1.push({arr[i],cnt});
            v[i]+=cnt;
        }
        int ans=0;
        for(int i=0;i<n;i++){ 
        int cnt=v[i]-1;
       // cout<<cnt<<" ";
        if(cnt>=arr[i])
        ans=max(ans,cnt);
        }
       // cout<<endl;
        return ans;
    }
};