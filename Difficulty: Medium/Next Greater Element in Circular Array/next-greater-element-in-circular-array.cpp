class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
    int n=arr.size();
    for(int i=0;i<n;i++) arr.push_back(arr[i]);
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<2*n;i++){
        
        while(!st.empty() and arr[i]>arr[st.top()]){
            if(st.top()<n) ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
        
    }
    return ans;
        
    }
};