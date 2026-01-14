class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n=arr.size();
        vector<int>v(n,0);
        v[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                v[i]=v[i-1]+1;
            }
            else{
                v[i]=1;
            }
        }
        
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                if(v[i+1]+1 > v[i]){
                   v[i]= v[i+1]+1; 
                }
                
            }
        }
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        int ans= accumulate(v.begin(),v.end(),0);
        return ans;
    }
};
