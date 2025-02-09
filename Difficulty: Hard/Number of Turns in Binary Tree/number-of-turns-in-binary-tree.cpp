//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  private:
  void f(Node* root,int d,string &path,string tmp){
      if(!root) return;
      if(root->data==d){
          path=tmp;
          return;
      }
      f(root->left,d,path,tmp+'L');
      f(root->right,d,path,tmp+'R');
      return;
  }
  public:
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      string p1="",p2="";
      f(root,first,p1,"");
      f(root,second,p2,"");
        int i=0,j=0;
        int n=p1.length();
        int m=p2.length();
        while(i<n and j<m and p1[i]==p2[j]){
            i++;
            j++;
        }
        // cout<<p1<<endl;
        // cout<<p2<<endl;
        // cout<<i<<" "<<j<<endl;
        int cnt1=0,cnt2=0;
        if(i<=n-1){
            cnt1=1;
            for(int k=i+1;k<n;k++){
                if(p1[k]!=p1[k-1]) cnt1++;
            }
        }
        if(j<=m-1){
            cnt2=1;
            for(int k=j+1;k<m;k++){
                if(p2[k]!=p2[k-1]) cnt2++;
            }
        }
      int ans=cnt1+cnt2-1;
      return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends