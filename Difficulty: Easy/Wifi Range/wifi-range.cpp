class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n= s.length();
        vector<array<int,2>>v;
        for(int i=0;i<n;i++){
            if(s[i]=='1') v.push_back({i-x,i+x});
        }
        if(v.size()==0) return false;
        if(v[0][0]>0) return false;
        if(v.back()[1]<(n-1)) return false;
        
        // for(auto it:v) cout<<it[0]<<" "<<it[1]<<endl;
        
        for(int i=1;i<v.size();i++){
            if((v[i][0]-v[i-1][1])>=2){
            // cout<<i<<endl;
            return false;
            }
        }
        return true;
        
    }
};