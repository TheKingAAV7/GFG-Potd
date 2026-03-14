/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<array<int,2>>v;
        map<int,array<int,2>> mp;
        
        function<void(Node*,int,int)>f=[&](Node* root,int pos,int depth)->void{
            if(!root) return ;
            if(mp.find(pos)==mp.end()){
                
                mp[pos]={depth,root->data};
            }
            else{
                if(mp[pos][0]>depth){
                    mp[pos][1]=root->data;
                    mp[pos][0]=depth;
                }
            }
            f(root->left,pos-1,depth+1);
            f(root->right,pos+1,depth+1);
           
            return;
        };
        
        f(root,0,0);
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto it:mp) ans.push_back({it.second[1]});
        return ans;
        
    }
};