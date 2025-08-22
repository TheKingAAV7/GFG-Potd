class Solution {
  public:
    vector<int> rabinKarp(string &txt, string &pat) {
        // code here
        vector<int>ans;
        int n=txt.length(),m=pat.length();
        string s=pat+"#"+txt;
        int sz=s.length();
        vector<int>z(sz,0);
        int l=0,r=0;
        for(int i=1;i<sz;i++){
            if(i<=r) z[i]=min(z[i-l],r-i+1);
            while(s[z[i]]==s[i+z[i]]) z[i]++;
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        }
        for(int i=m+1;i<sz;i++){
            if(z[i]==m){
                ans.push_back(i-m-1);
            }
        }
        return ans;
        
    }
};