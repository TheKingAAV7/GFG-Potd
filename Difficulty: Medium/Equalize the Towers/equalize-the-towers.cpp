#define ll long long
class Solution {
  public:
    int minCost(vector<int>& ht, vector<int>& c) {
        // code here
        vector<array<ll,2>>v;
        int n=ht.size();
        
        for(int i=0;i<n;i++) v.push_back({ht[i],c[i]});
        
        sort(v.begin(),v.end());
        
        vector<array<ll,2>>pref(n);
        ll prodsm=0;
        ll costsm=0;
        for(int i=0;i<n;i++){
            prodsm+=(v[i][0]*v[i][1]);
            costsm+=v[i][1];
            pref[i]={prodsm,costsm};
        }
        prodsm=0;
        costsm=0;
        ll ans=LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            
            ll lefsm,rigsm;
            lefsm=rigsm=0;
            if(i-1>=0){
            ll lefcsm= pref[i-1][1];
            ll lefprodsm=pref[i-1][0];
            lefsm= v[i][0]*lefcsm - lefprodsm;
            }
            
            
            ll rigcsm= costsm;
            ll rigprodsm= prodsm;
            rigsm= rigprodsm- v[i][0]*rigcsm;
            
            ll curval= lefsm+rigsm;
            ans= min(ans,curval);
            prodsm+=(v[i][0]*v[i][1]);
            costsm+=v[i][1];
            
        }
        return ans;
        
    }
};
