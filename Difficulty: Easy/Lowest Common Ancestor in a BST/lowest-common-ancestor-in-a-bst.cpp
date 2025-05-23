//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to Build Tree


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
  Node * ans=NULL;
  unordered_map<Node*,int>mp;
 bool f(Node* root, Node* tmp){
      if(!root) return false;
    
      if(root->data==tmp->data){
          if(mp.find(root)!=mp.end()) {
       
       
          if(!ans){
          ans=root;
          return true;
          }
          
      }
         mp[root]=1;
      return true;
      }
      
      bool f1=f(root->left,tmp);
      bool f2=f(root->right,tmp);
      
      
      if(f1 || f2){

      if(mp.find(root)!=mp.end()) {
       
       
          if(!ans){
          ans=root;
          return true;
          }
          
      }
      mp[root]=1;
      }
      return f1 || f2;
  }
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        f(root,n1);
        // for(auto it:mp){
        //     cout<<it.first->data<<endl;
        // }
        f(root,n2);
        
        if(!ans) return root;
        return ans;
    }
};


//{ Driver Code Starts.

Node* buildTree(string str) {
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
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node* n1 = new Node(l);
        Node* n2 = new Node(h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, n1, n2)->data;
        cout << ans << endl;
        cout << "~"
             << "\n";
    }
    return 1;
}
// } Driver Code Ends