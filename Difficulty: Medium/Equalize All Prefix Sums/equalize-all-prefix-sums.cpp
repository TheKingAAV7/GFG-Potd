class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        /*
        
        1 6 9 12
        
        1 6 9
        
        
        */
        int n= arr.size();
        int sm= 0;
        int lefsm=0;
        
        int curpos=-1;
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            sm+=arr[i];
            if(i%2==0){
                curpos++;
                lefsm+=arr[curpos];
            }
            
            int lefcnt= curpos+1;
            int rigcnt= (i+1)-lefcnt;
            int rigsm= sm-lefsm;
            // cout<<i
            
            int lefdiff= lefcnt*arr[curpos] - (lefsm);
            int rigdiff= rigsm-(rigcnt*arr[curpos]);
            ans.push_back(lefdiff+rigdiff);
        }
        return ans;
    }
};