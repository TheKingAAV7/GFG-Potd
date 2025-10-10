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
class Solution {
  public:
    map<Node*,int>mp;
    int ans=0;
    int ans2=INT_MIN;
    void f(Node* root){
        if(!root) return ;
        if(!root->left and !root->right){
            
            mp[root]=max(0,root->data);
            //cout<<mp[root]<<endl;
            ans=max(ans,mp[root]);
            ans2=max(ans2,root->data);
            return;
        }
        f(root->left);
        f(root->right);
        int lef=0;
        int rig=0;
        if(root->left)
        lef=max({0,mp[root->left]});
        if(root->right)
        rig=max({0,mp[root->right]});
        
        
        mp[root]=max({0,lef+root->data,rig+root->data});
        //cout<<root->data<<" "<<mp[root]<<endl;
        ans=max({ans,lef+root->data,rig+root->data,lef+root->data+rig});
        ans2=max(ans2,root->data);
        return ;
    }
    int findMaxSum(Node *root) {
        
        f(root);
        if(ans==0) return ans2;
        return ans;
        
    }
};