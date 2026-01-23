class Solution {
  public:
    int josephus(int n, int k) {
        // 1 3 5 
        int deleted=0;
        int pos=1;
        vector<int>vis(n+1,0);
        while(deleted<n-1){
            int pass=k-1;
            while(pass>0){
                if(vis[pos]==0){
                    pass--;    
                }
                if(pos+1<=n) pos++;
                else{
                    pos=1;
                }
             
            }
            
            while(vis[pos]==1){
            if(pos+1<=n) pos++;
                else{
                    pos=1;
                }
            }
            
           // cout<<pos<<" ";
            vis[pos]=1;
             deleted++;
             
             while(vis[pos]==1){
                 if(pos+1<=n) pos++;
                else{
                    pos=1;
                }
             }
           
            //cout<<pos<<endl;
             
        }
        return pos;
        
    }
};