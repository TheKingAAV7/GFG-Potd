class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        
        vector<array<int,3>>v;
        int n= a.size();
        for(int i=0;i<n;i++){
            v.push_back({a[i]-b[i],a[i],b[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int>pref(n,0),suff(n,0);
        
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=v[i][1];
            pref[i]=sm;
        }
        sm=0;
        for(int i=n-1;i>=0;i--){
            sm+=v[i][2];
            suff[i]=sm;
        }
    
        int ans=0;
        
        for(int i=0;i<min(x,n);i++){
            
            
            int poss= i+1; 
            if(i+1<n){
                int rig= max(poss,n-y);
                int cur= pref[i]+suff[rig];
                ans= max(ans,cur);
                
            }
            else{
                ans= max(ans,pref[i]);
            }
            
        }
        ans= max(ans,suff[max(n-y,0)]);
        
        return ans;
        
        
    }
};