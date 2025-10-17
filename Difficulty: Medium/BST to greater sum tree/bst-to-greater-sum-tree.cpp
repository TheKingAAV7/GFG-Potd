/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

/*
for each node, i should get 
1) sum1 from left tree 
2) sum2 from root
ans=total- sum1+sum2;

when calling right ptr, pass left sm; ->second
other wise 0; -> first
return lsm;


*/

class Solution {
  public:
  int total=0;
  void sm(Node* root){
      if(!root) return;
      total+=(root->data);
      sm(root->left);
      sm(root->right);
      return;
  }
  int lsm=0;
  
  void f(Node* root){ // returns left sum tree only
     if(!root) return ;
     f(root->left);
     int p=root->data;
     root->data=(total-lsm-p);
     lsm+=p;
     f(root->right);
     
     
     return ;
     
     
     
      
  }
    void transformTree(Node *root) {
       
       sm(root);
       f(root);
       return;
        
    }
};