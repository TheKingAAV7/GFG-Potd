class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
    int i=0,j=0;
    int n=s1.length(),m=s2.length();
    while(i<n and j<m){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    return i==n;
        
    }
};