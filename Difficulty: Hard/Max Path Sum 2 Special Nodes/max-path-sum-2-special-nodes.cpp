class Solution {
  public:
    int inf = -1000000000; // -1e9

    int f(Node* root, int &ans){
        if(root == NULL) return inf;                 // (1) NULL -> sentinel

        if(root->left == NULL && root->right == NULL){
            return root->data;                       // (2) leaf -> its value
        }

        int lef = f(root->left, ans);
        int rig = f(root->right, ans);

        // (3) only when both children exist can we form leaf-to-leaf through root
        if(root->left && root->right){
            ans = max(ans, root->data + lef + rig);
            return max(lef + root->data, rig + root->data);
        }
        // only one child exists: return path through that child
        return (root->left ? (lef + root->data) : (rig + root->data));
    }

    int maxPathSum(Node* root) {
         int ans = inf;
         int val = f(root, ans);      // val = best root->leaf sum
         if(ans == inf) ans = val;    // skew tree fallback
         return ans;
    }
};
