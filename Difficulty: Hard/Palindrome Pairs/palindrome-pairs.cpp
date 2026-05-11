class Solution {
  public:
    bool palindromePair(vector<string>& arr) {
        // Code here
        map<string,int>mp;
        for(string &s:arr) mp[s]++;
        for(string s:arr){
            int n= s.length();
            for(int len=0;len<n;len++){
                int lef= n-len;
               
                string comm= s.substr(lef);
                string revc= comm;
                reverse(revc.begin(),revc.end());
                if(comm==revc){
                string left= s.substr(0,lef);
                mp[s]--;
                string rev= left;
                reverse(rev.begin(),rev.end());
                
                if(mp[rev]>0){
                // cout<<s<<" "<<comm<<" "<<rev<<endl;
                return true;
                }
                mp[s]++;
                }
                
                {
                int lef= len;
               
                string comm= s.substr(0,lef);
                string revc= comm;
                reverse(revc.begin(),revc.end());
                if(comm==revc){
                string left= s.substr(lef);
                mp[s]--;
                string rev= left;
                reverse(rev.begin(),rev.end());
                
                if(mp[rev]>0){
                // cout<<s<<" "<<comm<<" "<<rev<<endl;
                return true;
                }
                mp[s]++;
                }
                    
                }
                
                
            }
        }
        return false;
        
    }
};