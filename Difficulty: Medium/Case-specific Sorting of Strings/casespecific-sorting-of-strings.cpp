class Solution {
  public:
    string caseSort(string& s) {
       vector<int>v1(26,0),v2(26,0);
       int n= s.length();
       for(int i=0;i<n;i++){
           if(s[i]>='A' and s[i]<='Z') v1[s[i]-'A']++;
           else v2[s[i]-'a']++;
       }
       
       int pos=0;
       for(char c='a';c<='z';c++){
          while(v2[c-'a']>0){
              while( s[pos]>='A' and s[pos]<='Z') pos++;
            
              s[pos]=c;
              v2[c-'a']--;
              pos++;
          } 
       }
       pos=0;
       for(char c='A';c<='Z';c++){
          while(v1[c-'A']>0){
              while( s[pos]>='a' and s[pos]<='z') pos++;
             
              s[pos]=c;
              v1[c-'A']--;
              pos++;
          } 
       }
       return s;
       
        
    }
};