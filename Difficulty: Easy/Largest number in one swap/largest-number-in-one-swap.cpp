class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        /*
        
        replace the leftmost with the maximum
        */
        int n=s.length();
        vector<int>suf(n,n-1);
        char maxi='0'-1;
        int idx=n-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]>maxi){
                maxi=s[i];
                idx=i;
            }
            suf[i]=idx;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]<s[suf[i+1]]){
                swap(s[i],s[suf[i+1]]);
                return s;
            } 
        }
        return s;
        
    }
};