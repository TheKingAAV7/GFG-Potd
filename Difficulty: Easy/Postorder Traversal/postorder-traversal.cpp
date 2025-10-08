/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
   void f(Node* root,vector<int>&ans){
       if(!root) return;
       f(root->left,ans);
       f(root->right,ans);
       ans.push_back(root->data);
       return;
   }
    vector<int> postOrder(Node* root) {
        vector<int>ans;
        f(root,ans);
        
        return ans;
        
    }
};