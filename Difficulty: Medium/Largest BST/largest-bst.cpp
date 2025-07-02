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
  public: // mini, maxi, cnt
    vector<int> f(Node* root,int &ans){
        if(!root) return {1e6,-1e6,0};
        if(!root->left and !root->right) return {root->data, root->data,1};
        vector<int>lef=f(root->left,ans);
        vector<int>rig=f(root->right,ans);
        int lef_max=lef[1];
        int rig_min=rig[0];
       
        if(lef_max<root->data and rig_min>root->data){
          //   cout<<root->data<<" "<<lef_max<<" "<<rig_min<<" "<<lef[2]+rig[2]+1<<endl;
            ans=max(ans,lef[2]+rig[2]+1);
              int mn = (lef[2] > 0 ? lef[0] : root->data);
    int mx = (rig[2] > 0 ? rig[1] : root->data);
    int sz=lef[2]+rig[2]+1;
    return { mn, mx, sz };
        }
        return {-1e6,1e6,0};
    }
    int largestBst(Node *root) {
       
       int ans=1;
      
       f(root,ans);
       return ans;
    
    }
};