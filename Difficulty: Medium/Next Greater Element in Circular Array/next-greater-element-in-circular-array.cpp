class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        // 9 7 3 1 4 2 10 9 8  9 7 3 1 4 2 10 9 8
        int n=arr.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++) arr.push_back(arr[i]);
        
        //cout<<arr.size()<<endl;
        stack<int>st;
        for(int i=0;i<2*n;i++){
            while(!st.empty() and arr[i]>arr[st.top()]){
                int pos=st.top();st.pop();
                if(pos<n)
                ans[pos]=arr[i];
            }
            st.push(i);
        }
        return ans;
    }
};