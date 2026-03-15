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
    int ans=0;
    void f(Node* root,map<int,int>&mp,int &k,int sm){
        if(!root) return;
        sm+=root->data;
        int x= sm-k;
        ans+=mp[x];
        mp[sm]++;
        f(root->left,mp,k,sm);
        f(root->right,mp,k,sm);
        mp[sm]--;
        return ;
        
    }
    int countAllPaths(Node *root, int k) {
        // code here
        map<int,int>mp;
        mp[0]=1;
        f(root,mp,k,0);
        return ans;
    }
};