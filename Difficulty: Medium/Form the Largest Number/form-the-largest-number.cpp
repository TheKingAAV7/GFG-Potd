class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        
        sort(arr.begin(),arr.end(),[&](int a, int b){
           string s1= to_string(a);
           string s2= to_string(b);
           string a1= s1+s2;
           string a2= s2+s1;
           return a1>=a2;
        });
        string ans;
        for(int i:arr) ans+=to_string(i);
        if(arr[0]==0) return "0";
        return ans;
        
    }
};