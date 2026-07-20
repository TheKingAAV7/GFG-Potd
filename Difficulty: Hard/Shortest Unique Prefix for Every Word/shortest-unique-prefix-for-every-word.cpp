
class Node{
   public:
   int val;
   vector<Node*>nxt;
   Node(){
       val=0;
       nxt.resize(26,NULL);
   }
};

class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        Node* root=new Node();
        Node* cur;
        for(auto &s:arr){
            cur= root;
            for(char &c:s){
                int cc= c-'a';
                if(!cur->nxt[cc]) cur->nxt[cc] = new Node();
                cur=cur->nxt[cc];
                cur->val+=1;
            }
        }
        vector<string>ans;
        for(auto &s:arr){
            string ss;
            bool found=false;
            cur=root;
            for(char &c:s){
               int cc= c-'a';
               cur=cur->nxt[cc];
               ss.push_back(c);
               if(cur->val==1){
                   found=true;
                   ans.push_back(ss);
                   break;
               }
            }
            if(!found) ans.push_back(s);
        }
        return ans;    
    }
};