class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n= arr.size();
        vector<int>pref,suff;
        pref.resize(n,0);
        suff.resize(n,0);
        set<int>st(arr.begin(),arr.end());
        if(st.size()==1) return 0;
        /*
        
        left -> 1
        right -> 0
        */
        
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1) cnt1++;
            pref[i]= cnt1;
        }
        int cnt0=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==0) cnt0++;
            suff[i]=cnt0;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int cost= pref[i];
            int cost1= (i+1<n)?suff[i+1]:0;
            ans=min(ans,cost+cost1);
            // int zero= (i+1)-cost;
            // int one=  n-i-1-cost1;
            // ans=min(ans,one+zero);
        }
        return min({suff[0],ans,pref[n-1]});
        
        
    }
};