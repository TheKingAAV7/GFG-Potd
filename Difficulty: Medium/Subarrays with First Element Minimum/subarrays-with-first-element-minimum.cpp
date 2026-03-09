class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>v(n,-1);
        vector<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i]<arr[st.back()]){
                v[st.back()]=i;
                st.pop_back();
            }
            st.push_back(i);
        }
        int ans=0;
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            int idx= v[i];
            if(idx==-1) ans+=(n-i);
            else ans+=(idx-i);
        }
        return ans;
        
    }
};