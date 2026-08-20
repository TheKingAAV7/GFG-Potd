/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int ans=INT_MIN;
    int f(Node* root){
        if(!root) return INT_MAX;
        if(!root->left and !root->right) return root->data;
        int lef= f(root->left);
        int rig= f(root->right);
        int tmp=min(lef,rig);
        // cout<<root->data<<" "<<tmp<<endl;
        ans=max(ans,root->data-tmp);
        return min(tmp,root->data);
    }
    int maxDiff(Node* root) {
        // code here
        
        f(root);
        return ans;
        
    }
};