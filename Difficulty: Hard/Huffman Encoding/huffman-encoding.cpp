class Node{
 public:
 int val;
 char c;
 int tim;
 Node* left;
 Node* right;
 Node(int x,char ch,int tim){
     val=x;
     c=ch;
     left=right=NULL;
     this->tim=tim;
 }
 
 
    
};

class Solution {
  public:
    vector<string>ans;
    void dfs(Node* root, string &s){
        if(!root) return;
        if(!root->left and !root->right){
            if(s=="") s="0";
            ans.push_back(s);
            // s.pop_back();
            return;
        }
        s.push_back('0');
        dfs(root->left,s);
        s.pop_back();
        s.push_back('1');
        dfs(root->right,s);
        s.pop_back();
        
        
        return;
    }
    vector<string> huffmanCodes(string &s, vector<int> f) {
        ans.clear();
        // Code here
     auto cmp = [](Node* a, Node* b) {
        if(a->val!=b->val)
        return a->val > b->val; 
        return a->tim > b->tim;
     };


    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        
    int n=s.length();
    for(int i=0;i<n;i++){
        Node* cur= new Node(f[i],s[i],i);
        pq.push(cur);
    }
    int cnt=n;
    while(pq.size()>1){
        auto lef= pq.top();
        pq.pop();
        auto rig= pq.top();
        pq.pop();
        
        int nval= lef->val+rig->val;
        Node* nn = new Node(nval,'{',min(lef->tim, rig->tim));
        nn->left= lef;
        nn->right=rig;
        pq.push(nn);
    }
    
    Node* root= pq.top();
    string cur;
    
    dfs(root,cur);
    
    return ans;
        
    }
};