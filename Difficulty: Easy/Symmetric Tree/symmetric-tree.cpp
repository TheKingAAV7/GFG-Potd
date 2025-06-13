/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  private:
  bool f(Node* root1, Node* root2){
      if(!root1 and !root2) return true;
      if(!root1 || !root2) return false;
      if(root1->data!=root2->data) return false;
      bool one=f(root1->left,root2->right);
      bool two=f(root1->right,root2->left);
      return one || two;
  }
  public:
    bool isSymmetric(Node* root) {

       
       return f(root->right,root->left);
        
    }
};