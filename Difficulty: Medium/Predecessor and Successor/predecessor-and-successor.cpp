class Solution {
  public:
    Node* mx, *mn;
    int maxi, mini;

    void f1(Node* root, int &key) {   // predecessor
        if(!root) return;

        if(root->data < key) {
            if(root->data > maxi) {
                maxi = root->data;
                mx = root;
            }
            f1(root->right, key);
        } else {
            f1(root->left, key);
        }
    }

    void f2(Node* root, int &key) {   // successor
        if(!root) return;

        if(root->data > key) {
            if(root->data < mini) {
                mini = root->data;
                mn = root;
            }
            f2(root->left, key);
        } else {
            f2(root->right, key);
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        mx = mn = NULL;
        maxi = INT_MIN;
        mini = INT_MAX;

        f1(root, key);
        f2(root, key);

        return {mx, mn};
    }
};