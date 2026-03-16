/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

const int MAXN=1e5+1;
class Solution {
  public:
    int ans=0;
    int dp[MAXN]={0};
    int f1(Node* root){
        if(!root) return 0 ;
        int lef=f1(root->left);
        int rig=f1(root->right);
        dp[root->data]=max({lef,rig})+1;
        return dp[root->data];
    }
    
    array<int,2> f(Node* root,int &target,int dep){
        if(!root) return {0,0};
        if(root->data==target){
            int lef= (root->left)? dp[root->left->data]:0;
            int rig= (root->right)? dp[root->right->data]:0;
            ans=max(ans,max(lef,rig));
            return {1,dep};
        }
        
        auto lef= f(root->left,target,dep+1);
        auto rig= f(root->right,target,dep+1);
        
        if(lef[0]){
            int rigval=  (root->right)? dp[root->right->data]:0;
            ans=max(ans,lef[1]-dep+rigval);
            
            
            return lef;
        }
        
        if(rig[0]){
            int lefval= (root->left)? dp[root->left->data]:0;
            ans=max(ans,rig[1]-dep+lefval);
            
            return rig;
        }
        return {0,0};
        
        
    }
    
    int minTime(Node* root, int target) {
        // code here
        f1(root);
        f(root,target,1);
        
        return ans;
        
        
    }
};