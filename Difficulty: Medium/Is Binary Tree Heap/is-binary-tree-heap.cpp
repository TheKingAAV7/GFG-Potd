//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  private:
   void f(Node* root,vector<Node*>&tmp,map<int,int>&mp,int cur,int &levl){
       if(!root) return;
       if(cur==levl-2){
           tmp.push_back(root);
       }
       mp[cur]++;
       f(root->left,tmp,mp,cur+1, levl);
       f(root->right,tmp,mp,cur+1,levl);
   }
   int lvl(Node* root){
       if(!root) return 0;
       queue<Node*>q;
       int cnt=0;
       q.push(root);
       while(!q.empty()){
           int n=q.size();
           for(int i=0;i<n;i++){
           Node* tmo=q.front();
           q.pop();
           if(tmo->left) q.push(tmo->left);
           if(tmo->right) q.push(tmo->right);
           }
           cnt++;
       }
       return cnt;
   }
   pair<bool,int> prop(Node* root){
       if(!root) return {true, -1};
       if(!root->left and !root->right){
           return {true,root->data};
       }
      auto lef=prop(root->left);
      auto rig=prop(root->right);
      if(((root->data)<max(lef.second,rig.second)) || ((lef.first & rig.first)==0)){
          return {false,-1};
      }
      return {true,root->data};
   }
  public:
    bool isHeap(Node* root) {
        if(!root->left and !root->right){
            return true;
        }
        int levl=lvl(root);
        vector<Node*>lastlvl;
        map<int,int>mp;
        f(root,lastlvl,mp,0,levl);
         
        int po=0;
       // cout<<levl<<endl;
        
        for(int i=0;i<levl-1;i++){
            if(mp[i]!=pow(2,po)){
                
                return false;
            }
            po++;
        }
       
        int cnt=0;
        // for(auto it:lastlvl) cout<<it->data<<" ";
        // cout<<endl;
        for(auto it:lastlvl){
            if(it->left) cnt++;
            else break;
            if(it->right) cnt++;
            else break;
        }
      //  cout<<cnt<<" "<<mp[levl]<<endl;
        if(cnt!=mp[levl-1]){
             
        return false;
        }
        
        
       auto it=prop(root);
       if(it.first){
           return true;
       }
       
       return false;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends