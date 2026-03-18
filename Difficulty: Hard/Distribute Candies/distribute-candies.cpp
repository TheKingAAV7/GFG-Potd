//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    map<Node*,int> st,candies;
    int ans=0;
    void dfs(Node * root){
        if(root==NULL)
        return ;
        st[root]=1;
        candies[root]=root->data;
        dfs(root->left);
        dfs(root->right);
        st[root]+=st[root->left]+st[root->right];
        candies[root]+=candies[root->left]+candies[root->right];
    }
    void dfs1(Node *root){
        if(!root) return;
        int lextra=candies[root->left]-st[root->left];
        int rextra=candies[root->right]-st[root->right];
        ans+=abs(lextra)+abs(rextra);
        dfs1(root->left);
        dfs1(root->right);
    }
    public:
   
    int distCandy(Node* root)
    {
        dfs(root);
        dfs1(root);
        return ans;
       
    }
};
