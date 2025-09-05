/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
       
       vector<array<int,2>>v;
       unordered_map<int,int>mp;
       queue<pair<Node*,int>>q;
       q.push({root,0});
      
       while(!q.empty()){
           Node* cur=q.front().first;
           int wd=q.front().second;
           q.pop();
           if(mp.find(wd)==mp.end()){
               mp[wd]=1;
               v.push_back({cur->data,wd});
           }
           if(cur->left) {
               q.push({cur->left,wd-1});
           }
           if(cur->right) q.push({cur->right,wd+1});
       }
       sort(v.begin(),v.end(),[&](array<int,2>&a, array<int,2>&b)->bool{
          return a[1]<b[1]; 
       });
       vector<int>ans;
       for(auto it:v) ans.push_back(it[0]);
       return ans;
       
        
    }
};