class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        //  2 2 2 2 
        int n=arr.size();
        vector<int>lef(n,0),rig(n,0);
        vector<array<int,2>>st,st1;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st.empty() and arr[i]<=st.back()[0]){
                cnt+=st.back()[1];
                st.pop_back();
            }
            lef[i]=cnt;
            st.push_back({arr[i],cnt});
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st1.empty() and arr[i]<st1.back()[0]){
                cnt+=st1.back()[1];
                st1.pop_back();
            }
            rig[i]=cnt;
            st1.push_back({arr[i],cnt});
        }
        // for(int i:lef) cout<<i<<" ";
        // cout<<endl;
        // for(int i:rig) cout<<i<<" ";
        // cout<<endl;
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=(lef[i]*rig[i]*arr[i]);
        }
        return sm;
    }
};