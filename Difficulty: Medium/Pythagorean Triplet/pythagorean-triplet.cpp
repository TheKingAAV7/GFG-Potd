class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
       int n=*max_element(arr.begin(),arr.end());
       vector<int>v((n*n+2),0);
       for(int i=0;i<arr.size();i++){
           v[arr[i]*arr[i]]++;
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               int t1=i*i;
               int t2=j*j;
               if(i==j){
                   if(v[t1]>=2){
                       if(v[t1+t2]!=0) {
                        //   cout<<v[t1+t2]<<endl;
                          // cout<<"YA"<<endl;
                            return true;
                       }
                      
                   } 
               }
               else{
                   if(v[t1] and v[t2] and ((t1+t2<=(n*n)) and v[t1+t2])){
                    //cout<<i<<" "<<j<<endl;
                    return true; 
                }
                   
               }
           }
       }
       return false;
        
    }
};