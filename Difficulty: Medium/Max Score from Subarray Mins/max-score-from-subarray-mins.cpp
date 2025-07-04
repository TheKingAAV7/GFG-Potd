class Solution {
  public:
    int maxSum(vector<int> &arr) {
        deque<int>dq; // 3 4 5
        int n=arr.size();
        multiset<int>st;
        st.insert(arr[0]);
        st.insert(arr[1]);
        auto it=st.begin();
        int fir=*it;
        it++;
        int sec=*it;
        int ans= fir+sec;
        int l=0;
        for(int i=2;i<n;i++){
            st.insert(arr[i]);
            while(st.size()>2){
                auto it1=st.find(arr[l]);
                // cout<<arr[l]<<endl;
                st.erase(it1);
                auto it=st.begin();
                int fir=*it;
                it++;
                int sec=*it;
                int tmp= fir+sec;
                ans=max(ans,tmp);
                
                l++;

            }
        }
        return ans;
        
    }
};