class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here  95 90  120 
        int n=arr.size();
        vector<int>ans(n,0);
        stack<array<int,2>>st;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st.empty() and arr[i]>=st.top()[1]){
                cnt+=st.top()[0];
                st.pop();
            }
            st.push({cnt,arr[i]});
            ans[i]= cnt;
        }
        return ans;
        
        
    }
};