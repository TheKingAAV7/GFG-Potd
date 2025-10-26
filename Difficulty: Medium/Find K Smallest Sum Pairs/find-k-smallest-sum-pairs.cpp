class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        /*
        
        a1 a2 a3 a4
        b1 b2 b3 b4
        
        let's push (ai,b1) in priority queue
        while pushing push the elements not positions
        */
        
        vector<vector<int>>ans;
        
          // sm, i, j
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        int m=arr2.size();
        for(int j=0;j<arr1.size();j++){
            int ele1=arr1[j];
            int ele2=arr2[0];
            pq.push({ele1+ele2,j,0});
        }
        while(!pq.empty() and k--){
            auto x=pq.top();
            pq.pop();
            int pos1=x[1];
            int pos2=x[2];
            ans.push_back({arr1[pos1],arr2[pos2]});
            int npos2=pos2+1;
            if(npos2<m){
                pq.push({arr1[pos1]+arr2[npos2],pos1,npos2});
            }
        }
        //for(auto it:ans) cout<<"( "<<it[0]<<" "<<it[1]<<" )"<<endl;
        return ans;
    }
};
