//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
//let us find the target node first  and parents in a map
 Node *targetNode;
    
    void tar(Node *root, int target , unordered_map<Node*,Node*>&parent ){
       
        if(root->data ==target ){
            targetNode =root;
        }
        
        if(root->left){
            parent[root->left]=root;
            tar(root->left,target,parent);
        }
        
        if(root->right){
            parent[root->right] =root;
            tar(root->right,target,parent);
        }
        
        return;
    }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {   
        unordered_map<Node* ,Node*>parent;
        targetNode =nullptr;
        tar(root,target,parent);
        
        queue<pair<Node*,int>>q;
        q.push({targetNode , 0 });
        
        unordered_set<Node*>visited;
        visited.insert(targetNode);
        vector<int>ans;
        
        while(!q.empty()){
            Node* node = q.front().first;
            int dis =q.front().second;
            
            q.pop();
            
            
            if(dis==k){
                ans.push_back(node->data);
                continue;
            }
            
            
            if(parent.find(node)!=parent.end()){
                if(visited.find(parent[node])==visited.end()){
                    visited.insert(parent[node]);
                    q.push({parent[node], dis+1});
                }
            }
            
            if(node->left && visited.find(node->left)==visited.end()){
                visited.insert(node->left);
                q.push({node->left ,dis+1});
            }
            
            if(node->right && visited.find(node->right)==visited.end()){
                visited.insert(node->right);
                q.push({node->right ,dis+1});
            }
        }
        
        sort(ans.begin() ,ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends