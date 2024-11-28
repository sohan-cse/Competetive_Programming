#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val): data(val),left(nullptr),right(nullptr){}
};

TreeNode*insert(TreeNode*root,int node_val){
    TreeNode* newnode=new TreeNode(node_val);
    if(!root)return newnode;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode * current_root=q.front();
        q.pop();

        if(!current_root->left){
            current_root->left=newnode;
            return root;
        }else{
            q.push(current_root->left);
        }

        if(!current_root->right){
            current_root->right=newnode;
            return root;
        }else{
            q.push(current_root->right);
        }
    }
    return root;
}

class Solution{
    public:
    int countNodes(TreeNode* root){
        if(!root)return 0;
        int left_tree_hight=findHeightLeft(root);
        int right_tree_height=findHeightRight(root);

        if(left_tree_hight==right_tree_height){
            return (1<<left_tree_hight)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int findHeightLeft(TreeNode*root){
        int height=0;
        while (root)
        {
            height++;
            root=root->left;
        }
        return height;
    }
    int findHeightRight(TreeNode*root){
        int height=0;
        while (root)
        {
            height++;
            root=root->right;
        }
        return height;
    }
};

int main(){
    TreeNode *root=nullptr;
    int n;
    cout<<"Enter number of node : ";
    cin>>n;
    cout<<"Enter tree node : ";
    for(int i=0;i<n;i++){
        int node_val;
        cin>>node_val;
        root=insert(root,node_val);
    }
    cout<<root->data;
    Solution sol;
    int totalNode=sol.countNodes(root);
    cout<<"Total node number is : "<<totalNode<<endl;
}