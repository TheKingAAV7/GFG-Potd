class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        //      1  2 3 4 5     
        vector<int>ans;
        multiset<int>st1,st2;
        // st1 contains smaller elements  answer will be in *st2.begin()
        for(int i:arr){
            if(st2.size()<k){
                st2.insert(i);
            }
            else{
                if(i< *(st2.begin())){
                    st1.insert(i);
                }
                else{
                   auto it= st2.begin();
                   int todel= *it;
                    st2.erase(it);
                    st1.insert(todel);
                    st2.insert(i);
                }
            }
            if(st2.size()<k) ans.push_back(-1);
            else ans.push_back(*st2.begin());
        }
        return ans;
        
    }
};