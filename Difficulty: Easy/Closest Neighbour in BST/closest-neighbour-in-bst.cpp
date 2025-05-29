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
  public:
    int findMaxFork(Node* root, int k) {
        int ans=-1;
        while(root!=NULL){
            
            if(root->data<=k){
                   ans=max(ans,root->data);
                root=root->right;
            }
            else {
             
            root=root->left;
            }
        }
        return ans;
        
    }
};