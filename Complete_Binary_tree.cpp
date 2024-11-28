#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* insert(Node *root,int data){
    Node* newnode=new Node(data);

    if(!root)return newnode;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* current_node=q.front();
        q.pop();
        if(!current_node->left){
            current_node->left=newnode;
            return root;
        }else{
            q.push(current_node->left);
        }

        if(!current_node->right){
            current_node->right=newnode;
            return root;
        }else{
            q.push(current_node->right);
        }
    }
    return root;
}

void InorderTraversal(Node* root){
    if(!root)return;
    InorderTraversal(root->left);
    cout<<root->data<<"  ";
    InorderTraversal(root->right);
}

void LevelorderTraversal(Node* root){
    if(!root)return;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* current_node=q.front();
        q.pop();
        cout<<"Current data : "<<current_node->data<<endl;
        if(current_node->left)q.push(current_node->left);
        if(current_node->right)q.push(current_node->right);
    }
    
}

int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int root_val;
    Node *root=nullptr;
    cout<<"Enter number of tree elements : ";
    for(int i=0;i<n;i++){
        cin>>root_val;
        root=insert(root,root_val);
    }
    cout<<"Inorder traversal : ";
    InorderTraversal(root);
    cout<<"\nLevel order traversal : ";
    LevelorderTraversal(root);

    return 0;
}