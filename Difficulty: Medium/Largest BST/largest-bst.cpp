/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int ans=0;
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    /*
    
    recursively check if the right min is greater than the current node
    AND left largest is smaller than current
    
    for each node, i will need left maximum , right minimum 
    and subtree size of both left node and right node
    also remember that both the right subtree and left subtree must be a
    bst
    
    
    {isbst,size,min,max}
    
    Check for leaf node.
    */
    array<int,4> f(Node* root){
        if(!root) return {1,0,INT_MAX,INT_MIN};
        auto lef= f(root->left);
        auto rig= f(root->right);
        if(lef[0] and rig[0]){
            if(lef[3]<root->data and root->data<rig[2]){ // maybe equals
                int cur=lef[1]+rig[1]+1;
                ans=max(ans,cur);
                return {1,cur,min(root->data,lef[2]),max(rig[3],root->data)};
            }
        }
        return {0,0,INT_MAX,INT_MIN};
        
    }
    
    int largestBst(Node *root) {
        // Your code here
        f(root);
        return ans;
    }
};