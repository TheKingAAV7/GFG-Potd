/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void toSumTree(Node *root) {
        // code here
        auto f=[&](auto &&self, Node* root)->int{
          if(!root) return 0;
          if(!root->left and !root->right ){
              int x= root->data;
              root->data=0;
              return x;
          }
          int lef = self(self, root->left);
          int rig= self(self, root->right);
          int sm= lef+rig;
          int ret= lef+rig+root->data;
          root->data= sm;
          return ret;
        };
        f(f,root);
        return;
        
    }
};