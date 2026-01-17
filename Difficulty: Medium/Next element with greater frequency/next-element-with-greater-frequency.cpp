class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n= arr.size();
        vector<int>ans(n,-1);
        map<int,int>mp;
        for(int &i:arr) mp[i]++;
        
        stack<array<int,2>>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top()[1]<mp[arr[i]]){
                ans[st.top()[0]]=arr[i];
                st.pop();
            }
            st.push({i,mp[arr[i]]});
        }
        return ans;
    }
};
