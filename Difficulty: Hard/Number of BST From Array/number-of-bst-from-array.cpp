

class Node{
 public:
 Node* left;
 Node* right;
 int data;
 Node(int data){
     this->data=data;
     this->left=NULL;
     this->right=NULL;
 }
};

void bfs(Node* root, vector<int>&vec){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
      int n=q.size();
      for(int i=0;i<n;i++){
          Node* tmp= q.front(); q.pop();
          vec.push_back(tmp->data);
          if(tmp->left) q.push(tmp->left);
          if(tmp->right) q.push(tmp->right);
      }
    }
    return ;
}
void f(Node* &root,int &d){
    if(!root) return ;
    
    if(root->data<d){
    if(!root->right){
    root->right= new Node(d);
    return;
    }
    else{
    f(root->right,d);
    }
    }
    else{
    if(!root->left){
        root->left= new Node(d); return;
    }
    else
    f(root->left,d);
    }
    return;
}
class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        vector<set<vector<int>>>v(16);
        vector<int>t1(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        int n=arr.size();
        do{
            Node* root=new Node(arr[0]);
            for(int i=1;i<n;i++){
                f(root,arr[i]);
            }
            vector<int>bf;
            bfs(root,bf);
            // for(int i:arr) cout<<i<<" ";
            // cout<<endl;
            // for(int i:bf) cout<<i<<" ";
            // cout<<endl;
            v[arr[0]].insert(bf);
            
            
        }while(next_permutation(arr.begin(),arr.end()));
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=v[t1[i]].size();
        }
        return ans;
    }
};