class Solution {
  public:
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int>ans;
        if(n==1) ans.push_back(0);
        auto f= [&](auto &&self, int i, int cur, int prev,bool zero)->void{
            if(i >= n){
                ans.push_back(cur);
                return;
            }
            if(prev==-1){
                for(int d=0;d<=9;d++){
                    if(d==0 ){
                        if(zero and cur>0) self(self,i+1,cur*10 + d, d,0);
                    }
                    else
                    self(self,i+1,cur*10 + d, d,0);
                }
            }
            else{
                for(int d=prev+1;d<=9;d++){
                    if(cur*10+d != cur)
                    self(self,i+1,cur*10 + d, d,0);
                }
            }
            return;
            
        };
        f(f,0,0,-1,1);
        
        return ans;
        
    }
};