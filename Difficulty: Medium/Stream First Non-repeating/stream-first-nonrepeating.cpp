class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n=s.length();
        vector<array<int,2>>vis(26,{-1,0});
        string ans;
        char prev='.';
        for(int i=0;i<n;i++){
            vis[s[i]-'a'][1]++;
            vis[s[i]-'a'][0]=i;
            
            int pos=INT_MAX;
            for(int j=0;j<26;j++){
                if(vis[j][1]==1){
                    if(vis[j][0]<pos){
                        pos=vis[j][0];
                    }
                }
            }
            if(pos==INT_MAX) ans.push_back('#');
            else ans.push_back(s[pos]);
        }
        return ans;
        
    }
};