class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        if(type==1){
            while(k--){
               int ls=dq.back();
               dq.pop_back();
               dq.push_front(ls);
            }
        }
        else{
            while(k--){
            int fr=dq.front();
            dq.pop_front();
            dq.push_back(fr);
            }
        }
        return ;
    }
};