class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        // 885446
        int n=s.length();
        vector<int>mx(n,-1);
        char maxi='.';
        int pos=-1;
        for(int i=n-1;i>=0;i--){
            mx[i]=pos;
            if(maxi=='.' || s[i]>maxi){
                maxi=s[i];
                pos=i;
            }
           
        }
        // for(int c:mx) cout<<c<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(mx[i]!=-1 and s[mx[i]]>s[i]) {
                swap(s[mx[i]],s[i]);
                break;
            }
        }
        return s;
    }
};