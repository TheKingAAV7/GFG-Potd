/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
   int sm=0;
   void f(Node* root,int &l,int &r){
       if(!root) return ;
       f(root->left,l,r);
       if(root->data>=l and root->data<=r){
           sm+=root->data;
       }
       f(root->right,l,r);
       return;
   }
  
    int nodeSum(Node* root, int l, int r) {
        // code here
        f(root,l,r);
        return sm;
    }
};
