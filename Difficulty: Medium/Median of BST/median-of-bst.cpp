/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  vector<int>ans;
  void f(Node* root){
      if(!root) return; 
      f(root->left);
      ans.push_back(root->data);
      f(root->right);
      return ;
  }
    int findMedian(Node* root) {
        // Code here
        
        f(root);
        int n=ans.size();
        int pos=0;
        if(n%2==0){
            pos=n/2;
        }
        else pos=(n+1)/2;
        return ans[pos-1];
        
    }
};