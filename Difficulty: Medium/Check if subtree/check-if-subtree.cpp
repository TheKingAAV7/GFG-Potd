/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isSubTree(Node *root1, Node *root2, bool flag=false) {
        // code here
        if(!root1 and !root2) return true;
        if(!root1 || !root2) return false;
        
        // if(!root1->left and !root1->right and !root2->left and !root2->right) return root1->data==root2->data;
        // if(root1->data!= root2->data) return 
        if(flag){
            if(root1->data!=root2->data) return false;
            bool ans= false;
            ans|= isSubTree(root1->left, root2->left,true) and isSubTree(root1->left,root2->left,true);
            return ans;
        }
        bool ans= false;
        if(root1->data==root2->data){
            ans|= isSubTree(root1->left, root2->left,true) and isSubTree(root1->left,root2->left,true);
        }
        ans|= isSubTree(root1->left, root2,false) || isSubTree(root1->right,root2,false);
        return ans;
        
    }
};