/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};



first find out a LCA and 

*/

class Solution {
  public:
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        map<Node*,int>mp;
        
        Node* LCA=NULL;
        auto f=[&](auto &&self, Node* root )->vector<int>{
         if(!root) return {};
         
        
         auto lef= self(self,root->left);
         auto rig= self(self,root->right);
         
         
         if(root->data==p) lef.push_back(p);
         if(root->data==q) rig.push_back(q);
         
         set<int>st(lef.begin(),lef.end());
         for(int i:rig) st.insert(i);
         vector<int>v(st.begin(),st.end());
         if((int)(v.size())==2 and !LCA){
          LCA=root;
         }
         return v;
        };
        
        f(f,root);
        
        int a, b;
        a=b=0;
        auto f1=[&](auto &&self, Node* root, int &val, int prev,int turns)->void{
            if(!root) return;
            if(root->data==val){
                if(val==p) a=turns;
                else b= turns;
                return;
            }
            self(self,root->left,val,0,turns+(prev!=0));
            self(self,root->right,val,1,turns+(prev!=1));
            return;
        };
        
        // cout<<LCA->data<<endl;
        f1(f1,LCA,p,-1,0);
        f1(f1,LCA,q,-1,0);
        
        // cout<<a<<" "<<b<<endl;
        
        int ans= a+b;
        if(ans==1) return -1;
        
        
        return ans-1;
        
    }
};