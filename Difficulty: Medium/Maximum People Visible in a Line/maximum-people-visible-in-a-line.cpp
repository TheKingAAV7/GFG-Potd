class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n= arr.size();
        
        vector<int>v(n,0);
        stack<array<int,2>>st1,st2;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st1.empty() and arr[i]>st1.top()[0]){
                cnt+=st1.top()[1];
                st1.pop();
            }
            v[i]=cnt;
            st1.push({arr[i],cnt});
        }
        
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st2.empty() and arr[i]>st2.top()[0]){
                cnt+=st2.top()[1];
                st2.pop();
            }
            v[i]+=cnt;
            st2.push({arr[i],cnt});
        }
        
        
        int ans= *max_element(v.begin(),v.end());
        return ans-1;
        
    }
};