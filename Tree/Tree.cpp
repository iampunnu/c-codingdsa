#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode * left;
    TreeNode * right;
    int data;
    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};

class Tree
{
public:
        TreeNode* root;
public:
    Tree(){
        this->root=NULL;

    }
    TreeNode * insert(){
        TreeNode* root=NULL;
        cout<<"enter data"<<endl;
        int data;
        cin>>data;
        if(data==-1){
            return NULL;
        }
        root=new TreeNode(data);

        cout<<"enter left of "<<data<<endl;
        root->left=insert();
        cout<<"enter right of "<<data<<endl;
        root->right=insert();
        return root;
    }
    void preorder(TreeNode * root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    bool path(TreeNode * root,vector<int>&  v,int data){
        if(root==NULL){
            return false;
         }
         v.push_back(root->data);
         if(root->data==data){
            return true;
         }
         if(path(root->left,v,data) || path(root->right,v,data)){
            return true;
         }
         v.pop_back();
         return false;

    }
    int height(TreeNode * root){
        if(root==NULL){
            return 0;

        }
        return(1+std::max(height(root->left),height(root->right)));
    }
    int diameter(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        return(std::max(lh+rh+1,std::max(diameter(root->left),diameter(root->right))));
    }
    int maxInTree(TreeNode * root){
        if(root==NULL){
            return INT_MIN;
        }
        return (std::max(root->data,std::max(maxInTree(root->left),maxInTree(root->right))));
    }
    ~Tree();
};

int main(){

    Tree* tree=new Tree();
    tree->root=tree->insert();
    tree->preorder(tree->root);
    vector<int> g1;
    tree->path(tree->root,g1,11);
    cout<<endl;
      for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 
    cout<<endl;
    cout<<tree->height(tree->root)<<endl;    
    cout<<tree->diameter(tree->root)<<endl;
    cout<<tree->maxInTree(tree->root)<<endl;




    return 0;
}

