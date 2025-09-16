class Solution {
  public:
    string f(string &s,int lef, int rig, int &n,vector<int>&pos){
        
        string ans="";
        for(int i=lef;i<=rig;i++){
            if(isdigit(s[i])) {
                int num=0;
                while(i<=rig and isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                int righti=pos[i];
                string mid=f(s,i+1,righti-1,n,pos);
                while(num--) ans+=mid;
                i=righti;
            }
            else{
                ans.push_back(s[i]);
            }
            
        }
        return ans;
    }
    string decodedString(string &s) {
        // code here
        string ans="";
        int n=s.length();
         vector<int>pos(n,-1);
         vector<int>st;
         for(int i=0;i<n;i++){
             if(s[i]=='[') st.push_back(i);
             else if(s[i]==']'){
                 int va=st.back();
                 st.pop_back();
                 pos[va]=i;
             }
         }
        //  for(int i:pos) cout<<i<<" ";
        //  cout<<endl;
        int lef=0,rig=s.length()-1;
       // return "";
        return f(s,lef,rig,n,pos);
    }
};