class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        //  a1 a2 a3 a4 a5 a6
        //  a1 a2 a3
        //  a4 a5 a6
        vector<int>tmp;
        while(!q.empty()){
            int cur= q.front();
            q.pop();
            tmp.push_back(cur);
        }
        int sz=tmp.size();
        for(int i=0;i<sz/2;i++){
            q.push(tmp[i]);
            q.push(tmp[sz/2+i]);
        }
        return ;
    }
};