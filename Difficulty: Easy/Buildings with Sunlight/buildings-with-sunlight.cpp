class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        stack<int>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[i]>st.top()){
                st.pop();
            }
            st.push(arr[i]);
        }
        return (int)(st.size());
    }
};