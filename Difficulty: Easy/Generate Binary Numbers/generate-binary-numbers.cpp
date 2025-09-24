class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        for(int i=1;i<=n;i++){
            int x=i;
            string tmp="";
            while(x){
                if(x&1){
                    tmp.push_back('1');
                }
                else tmp.push_back('0');
                x=x>>1;
            }
            reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};