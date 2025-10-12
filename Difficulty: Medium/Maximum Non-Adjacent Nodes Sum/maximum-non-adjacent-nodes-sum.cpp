/*
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
    int ans=0;
    map<Node*,int>dp;
    void f(Node* root){
        if(!root) return;
        if(!root->left and !root->right){
            ans=max(ans,root->data);
            dp[root]=root->data;
            return;
        }
        
        f(root->left);
        f(root->right);
        dp[root]=0;
        // ntakee
        int lef=0,rig=0;
        int lef1=0,rig1=0;
        if(root->left) lef1=max(lef1,dp[root->left]);
        if(root->right) rig1=max(rig1,dp[root->right]);
         
        dp[root]=max(dp[root],lef1+rig1);
        if(root->left){
            if(root->left->left) lef+=dp[root->left->left];
            if(root->left->right) lef+=dp[root->left->right];
        }
        
        if(root->right){
            if(root->right->left) rig+=dp[root->right->left];
            if(root->right->right) rig+=dp[root->right->right];
        }
        
        dp[root]=max(dp[root],root->data+lef+rig);
        //cout<<root->data<<" "<<dp[root]<<endl;
        ans=max(ans,dp[root]);
        return ;
    }
  public:
    int getMaxSum(Node *root) {
       f(root);
       return ans;
         
    }
};