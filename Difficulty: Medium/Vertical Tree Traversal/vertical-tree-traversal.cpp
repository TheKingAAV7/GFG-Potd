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
    map<int,vector<array<int,2>>>mp;
    map<Node*,int>level;
    
    void f(Node* root,int depth){
        if(!root) return ;
        mp[depth].push_back({level[root],root->data});
        f(root->left,depth-1);
        f(root->right,depth+1);
        return;
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        queue<Node*>q;
        int lvl=0;
        q.push(root);
        while(!q.empty()){
            int sz= q.size();
            for(int i=0;i<sz;i++){
                Node* cur= q.front();q.pop();
                level[cur]=lvl++;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
           
        }
        
        f(root,0);
        vector<vector<int>>ans;
        for(auto &it:mp){
            vector<int>tmp;
            sort(it.second.begin(),it.second.end());
            for(auto i:it.second) tmp.push_back(i[1]);
            ans.push_back(tmp);
        }
        return ans;
    }
};