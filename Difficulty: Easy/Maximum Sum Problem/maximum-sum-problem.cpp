class Solution {
  public:
    int maxSum(int n) {
        // code here.
        /*
        12 12 12
        13 13 13
        
        36
        
        18+12+9
        
        
        
        */
        
        auto f=[&](auto &&self, int cur)->int{
            int nval= (cur/2+cur/3+cur/4);
            if(nval<=cur) return cur;
            
            return self(self,cur/2)+ self(self,cur/3)+self(self,cur/4);
        };
        
        return f(f,n);
    }
};