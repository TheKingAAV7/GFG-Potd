class Solution {
  public:
    int minCost(vector<int>& h, vector<int>& c) {
        int n=h.size();
        long long ans=LLONG_MAX;
        vector<pair<long long,long long>>v;
        for(int i=0;i<n;i++) v.push_back({h[i],c[i]});
        sort(v.begin(),v.end());
        vector<long long>pref(n,0),csm(n,0);
        long long sm=0;
        long long sm1=0;
        for(int i=n-1;i>=0;i--){
            long long tmp=v[i].first*v[i].second;
            sm+=tmp;
            sm1+=v[i].second;
            pref[i]=sm;
            csm[i]=sm1;
        }
        long long lefsm=0,lefsm1=0;
        for(int i=0;i<n;i++){
            lefsm1+=v[i].second;
            lefsm+=(v[i].first*v[i].second);
            
            long long right=(pref[i]-(v[i].first*csm[i]));
            long long left=(v[i].first*lefsm1)-(lefsm);

            ans=min(ans,left+right);
            
        }
        return (int)ans;
        
    }
};
