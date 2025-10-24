class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        /*
        
        find minimum no. of operations to make 
        sm of all elements <= (cur_sm/2)
        operation -> replace a->a/2; floating point precision
        if(we divide all the elements by 2) it will fine..
        9 4
        4.5
        use binary search?
        apply operations only on the greater elements.. first
        so sort them...
        no, use heap, and always pick an element with 
        max value, half it, and subtract it from cur_sm 
        */
        
        // not sure about lo=0
        
        priority_queue<double>pq;
        for(int i:arr) pq.push(1.0*i);
        double sm=0;
        for(int i:arr) sm+=(double)(i);
         //  9 2 1
        int cnt=0;
        double req=(double)sm/2;
        //cout<<req<<endl;
        while(sm>req){
            double topi=pq.top();
            pq.pop();
            topi/=(2.0);
            sm-=(topi);
            pq.push(topi);
            cnt++;
        }
        return cnt;
        
        
    }
};