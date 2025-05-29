/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  private:
  pair<int,int>f(Node *root){
      if(root==NULL) return {0,0};
      pair<int,int>a=f(root->right);
      pair<int,int>b=f(root->left);
      if(a.second>b.second){
         return {root->data+a.first,1+a.second};
      }
      else if(a.second==b.second){
          return {root->data+max(a.first,b.first),1+a.second};
      }
      return {root->data+b.first,1+b.second};
  }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        
        pair<int,int>ans=f(root);
        return ans.first;
        
        
    }
};