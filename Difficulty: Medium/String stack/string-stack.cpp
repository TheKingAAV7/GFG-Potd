class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int n=pat.length();
        int m=tar.length();
        int pos=0;
        //evod
        int req=0;
        int last=-1;
        for(int i=0;i<n;i++){
            if(pat[i]==tar[pos]){
                if(i%2==req){
                last=i;
                pos++;
                req=!req;
                }
            }
        }
        if(pos==m){ 
    
        if ((n-last-1)%2==0) return true;
        }
     
        
        req=1;
        last=-1;
        pos=0;
        for(int i=0;i<n;i++){
            if(pat[i]==tar[pos]){
                if(i%2==req){
                last=i;
                pos++;
                req=!req;
                }
            }
        }
        if(pos==m){ 
           
        return (n-last-1)%2==0;
        }
         
        return false;
    }
};