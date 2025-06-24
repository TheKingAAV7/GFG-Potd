class Solution {
  public:
    bool sameFreq(string& s) {
       vector<int>mp(26,0);
       for(char c:s) mp[c-'a']++;
       int a=-1, b=-1;
       int cnta=0,cntb=0;
       for(int i=0;i<26;i++){
           if(mp[i]>0){
               if(a==-1){
                   a=mp[i];
                   cnta=1;
                
               }
               else{
                   if(mp[i]!=a and b==-1) {
                   b=mp[i];
                   cntb=1;
                   }
                   else if(mp[i]!=a and mp[i]!=b) return false;
                   else{
                       if(mp[i]==a) cnta++;
                       else cntb++;
                   }
               }
           }
       }
       
       // 3->2 and 2->1
       if(b==-1) return true;
   // cout<<cnta<<" "<<cntb<<endl;
      if (cnta==1 && (a==1 || a-b==1)) return true;
if (cntb==1 && (b==1 || b-a==1)) return true;
return false;

        return false;
    }
};