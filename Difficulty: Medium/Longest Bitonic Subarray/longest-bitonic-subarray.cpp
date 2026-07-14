class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n= arr.size();
        vector<int>pref(n,0),suff(n,0);
        int prev=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=prev) cnt++;
            else  cnt=1;
            prev=arr[i];
            pref[i]=cnt;
        }
        prev=cnt=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=prev) cnt++;
            else cnt=1;
            prev=arr[i];
            suff[i]=cnt;
        }
        int ans= max(suff[0],pref.back());
        for(int i=1;i<n-1;i++){
            int cur= arr[i];
            int lef= pref[i-1];
            int rig= suff[i+1];
            if(cur>=arr[i-1] and cur>=arr[i+1]) ans=max(ans,1+lef+rig);
        }
        return ans;
        
    }
};