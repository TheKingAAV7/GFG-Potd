class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        /*
         10     20    30    50    10    70     30 
        (1,4)  (1,3) (1,2) (1,1) (5,3) (1,1)  (2,1)
        
        */
        /*
        
       1->70
       2->30
       3->20
       4->10
        */
        int n=arr.size();
        stack<pair<int,int>>st,st1;
        vector<int>lef(n,1),rig(n,0);
        for(int i=0;i<n;i++){
            int cur=1;
            while(!st.empty() and arr[i]<=st.top().first){
                int cnt=st.top().second;
                st.pop();
                cur+=cnt;
            }
            lef[i]=cur;
            st.push({arr[i],cur});
        }
        for(int i=n-1;i>=0;i--){
            int cur=1;
            while(!st1.empty() and arr[i]<=st1.top().first){
                int cnt=st1.top().second;
                cur+=cnt;
                st1.pop();
            }
            rig[i]=cur;
            st1.push({arr[i],cur});
        }
        priority_queue<array<int,2>>pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],lef[i]+rig[i]-1});
           // cout<<"( "<<lef[i]<<" "<<rig[i]<<" ) ";
        }
        int mini=*min_element(arr.begin(),arr.end());
        vector<int>ans(n+1,mini);
        int pos=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int ele=it[0];
            while(pos<=n and pos<= it[1] ){
                ans[pos]=ele;
                pos++;
            }
        }
        ans.erase(ans.begin());
        
        
        
        return ans;
    }
};