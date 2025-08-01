class Solution {
  public:
    int countBalanced(vector<string>& arr) {
       unordered_map<int,int>mp;
       set<int>vow={'a','e','i','o','u'};
       int diff=0;
       int ans=0;
       mp[0]=1;
       for(auto it:arr){
           for(char c:it){
               if(vow.find(c)!=vow.end()) diff++;
               else diff--;
           }
           ans+=(mp[diff]);
           mp[diff]++;
       }
       return ans;
       
      
    }
};