class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        map<int,int>mp;
        
        int n=arr.size();
        vector<int>ans(n,-1);
        for(int i:arr) mp[i]++;
        stack<int>st;
        for(int i=0;i<n;i++){
         while(!st.empty() and mp[arr[i]]>mp[arr[st.top()]]){
             ans[st.top()]=arr[i];
             st.pop();
         }
         st.push(i);
        }
        return ans;
        
    }
};
