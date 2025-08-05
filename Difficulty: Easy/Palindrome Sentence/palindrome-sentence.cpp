class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int n=s.length();
        int i=0,j=n-1;
        
        while(i<j and (!isalnum(s[i]))){
            i++;
        }
        while(i<j and (!isalnum(s[j]))){
            j--;
        }
        while(i<j){
           if(tolower(s[i])==tolower(s[j])){
           i++;
           j--;
           }
           else return false;
        while(i<j and (!isalnum(s[i]))){
            i++;
        }
        while(i<j and (!isalnum(s[j]))){
            j--;
        }
           
        }
        
        return true;
        
    }
};