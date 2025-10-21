class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        /*
        every element is atmost k positions away from its correct
        pos..
        
        let's try to define some ranges for each element
        
        2-> (0-2)
        3-> (0-3)
        1-> (0-3)
        4-> (1,3)
        
        for each size of k from left to right , find out the smallest
        element and replace it with current left.
        
            maintain a maxheap;;
            you have to remove as well, but its' guaranted that
            always smaller element will be removed.
        */
        
        int n=arr.size();
        int l=0,i=0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        while(i<n){
           pq.push(arr[i]);
           
           if(i-l+1>k){
               
              arr[l]=pq.top();
              pq.pop();
              l++;
           } 
            i++;
        }
        while(l<n and !pq.empty()){
            arr[l++]=pq.top();
            pq.pop();
        }
        return ;
    }
};