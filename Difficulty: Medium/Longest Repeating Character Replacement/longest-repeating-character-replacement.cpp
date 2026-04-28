class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n= s.length();
        
        int ans=1;
        
        for(char c='A';c<='Z';c++){
        int cost=0;
        int l=0;
        for(int i=0;i<n;i++){
            if(s[i]!=c) cost++;
            while(cost>k){
                if(s[l]!=c) cost--;
                l++;
            }
            // if(i-l+1==4) cout<<c<<endl;
            ans=max(ans,i-l+1);
        }
        }
        return ans;
    }
};