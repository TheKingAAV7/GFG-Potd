class Solution {
  public:
  
    void replaceElements(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int last = arr[n-1]^arr[n-2];
        
        int sum = arr[0];
            
        arr[0] = arr[0]^arr[1];
        
        if(n==2)
        {
            arr[n-1]=last;
            return;
        }
        
        for(int i=1;i<n-1;i++)
        {
            int prev=arr[i];
            arr[i]=sum^arr[i+1];
            sum=prev;
        }
        
        arr[n-1]=last;
    }
};