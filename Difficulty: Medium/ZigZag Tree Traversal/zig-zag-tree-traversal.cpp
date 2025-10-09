/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        vector<int>ans;
        int od=1;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                Node* tmp=q.front();
                v.push_back(tmp->data);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            if(od){
                for(int i:v) ans.push_back(i);
            }
            else {
                while(!v.empty()){
                    ans.push_back(v.back());
                    v.pop_back();
                }
            }
            od=!od;
        }
        return ans;
        
    }
};