/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int>ans,res;
        function<void(Node*)>f=[&](Node* root){
          if(!root) return;
          f(root->left);
          ans.push_back(root->data);
          f(root->right);
          return;
        };
        f(root);
        sort(ans.begin(),ans.end(),[&](int &a, int &b){
           int diff1=abs(a-target);
           int diff2=abs(b-target);
           if(diff1==diff2) return a<b;
           return diff1<diff2;
        });
        for(int i=0;i<min((int)ans.size(),k);i++) res.push_back(ans[i]);
        return res;
        
        
    }
};