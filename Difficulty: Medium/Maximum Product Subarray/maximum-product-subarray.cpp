class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        
        /*
        
        Obs:
        1)Problem with 0 -> 0 makes partitions
        2) count of -ves -> should be even
        
        Count the total no. of negative elements
        
        if it's even , then we can take all 
        but what if there's a zero somewhere?
        
        even no. of negatives is good for us
        
        for each negative element make it a
        
        
         + -  + - - - - +
         if(negatives are od)
         either remove till first lef negative
         or first right neg..
         else{
             take all product
         }
         
         case of no zero
        */
        int ans=*max_element(arr.begin(),arr.end());
        if(arr.size()==1) return ans;
        arr.push_back(0);
        int n=arr.size();
    
        int prod=1;
        bool newstart=true;
        int firstneg=-11;
        int cntneg=0;
        int lstneg=-1;
        int sz=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(cntneg%2==0){
                    ans=max(ans,prod);
                }
                else{
                    if(sz==1){
                        
                    }
                    else{
                    // remove first neg
                    int rigprod= prod/firstneg;
                    int lefprod= lstneg;
                   // cout<<rigprod<<" "<<lefprod<<endl;
                    ans=max({ans,rigprod,lefprod});
                    }
                }
                prod=1;
                sz=0;
                cntneg=0;
                firstneg=-11;
                lstneg=-1;
                ans=max(ans,0);
                newstart=true;
                continue;
            }
            
            
            
            sz++;
            if(arr[i]<0){
                cntneg++;
                lstneg=prod;
                prod*=arr[i];
                if(firstneg==-11) firstneg=prod;
            }
            else{
                prod*=arr[i];
            }
        }
        return ans;
        
        
    }
};