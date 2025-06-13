class Solution {
  private:
  int binpowmod(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
    res = (int)((1LL * res * a) % m);
a = (int)((1LL * a * a) % m);
        b >>= 1;
    }
    return res;
}
  public:
  int mod=1e9+7;
    vector<int> search(string &pat, string &txt) {
       int n=pat.length();
       int m=txt.length();
       int p=31;
       
       vector<int>ans;
       long long hsh=0;
       long long po=1;
     
       long long hsh1=0;
       for(int i=0;i<n;i++){
           hsh=(hsh%mod+((long long)(pat[i]-'a'+1)*po)%mod)%mod;
           hsh1=(hsh1%mod+((long long)(txt[i]-'a'+1)*po)%mod)%mod;
           po=(po%mod*p%mod)%mod;
       }
       if(hsh==hsh1) ans.push_back(1);
       
       
      
       int invo=binpowmod(p,mod-2,mod);
       po=(po%mod*invo%mod)%mod;
       for(int i=n;i<m;i++){
          
           hsh1=(hsh1-(long long)(txt[i-n]-'a'+1)+mod)%mod;
            hsh1=(hsh1%mod*invo%mod)%mod;
           hsh1=(hsh1%mod+((long long)(txt[i]-'a'+1)*po)%mod)%mod;
           if(hsh==hsh1) ans.push_back(i-n+2);
       }
       return ans;
    }
};