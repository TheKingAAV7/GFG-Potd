/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void f(Node* root, map<int,pair<int,int>>&mp,int cnt,int depth){
        if(!root) return;
        
        f(root->left,mp,cnt-1,depth+1);
        f(root->right,mp,cnt+1,depth+1);
        if(mp.find(cnt)!=mp.end() and mp[cnt].second<=depth){
            mp[cnt]={root->data,depth};
        }
        else if(mp.find(cnt)==mp.end()){
            mp[cnt]={root->data,depth};
        }
        return;
    }
    vector<int> bottomView(Node *root) {
      map<int,pair<int,int>>mp;
      f(root,mp,0,0);
      vector<int>ans;
      for(auto it:mp){
          ans.push_back(it.second.first);
      }
      return ans;
        
    }
};