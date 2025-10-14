/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  vector<int>ans;
    void f(Node* root){
        if(!root) return ;
        f(root->left);
        ans.push_back(root->data);
        f(root->right);
        return;
    }
    int kthSmallest(Node *root, int k) {
        
        f(root);
        
        int n=ans.size();
        if(k<=n) return ans[k-1];
        return -1;
        
    }
};