/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        
        map<int,int>mp;
        
        auto f=[&](auto &&self, Node* root, int cur)->void{
            if(!root) return ;
            mp[cur]+=root->data;
            self(self,root->left,cur-1);
            self(self,root->right,cur+1);
            return;
        };
        f(f,root,0);
        vector<int>ans;
        for(auto it:mp) ans.push_back(it.second);
        return ans;
        
    }
};