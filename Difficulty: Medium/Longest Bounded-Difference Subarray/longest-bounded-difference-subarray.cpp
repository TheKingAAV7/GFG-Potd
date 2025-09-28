class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
       // code here
       multiset<int>st;
       int n=arr.size();
       int l=-1,r=-1;
       int len=-1;
        int lef=0;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
            while(abs(*st.begin()- *(prev(st.end())))>x){
                auto it=st.find(arr[lef]);
                st.erase(it);
                lef++;
            }
            int curlen=(i-lef+1);
            if(curlen>len){
                len=curlen;
                l=lef;
                r=i;
            }
        }
        vector<int>ans;
        for(int i=l;i<=r;i++) ans.push_back(arr[i]);
        return ans;
        
    }
};