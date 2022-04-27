#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

struct Node* insert(struct Node* root,int data){

    if(root == NULL){
        return createNode(data);
    }
    else if(data >= root->data){
        root->right = insert(root->right, data);
    }
    else if(data < root->data){
        root->left = insert(root->left, data);
    }
    return root;
}

int search(struct Node* root, int data){

    if(root->data == NULL){
        cout<<"No data is found";
        return 0;
    }
    else if(root->data == data){
        return root->data;
    }
    else if(data >= root->data){
        return search(root->right, data);
    }
    else
        return search(root->left, data);
}

void findMinimum(struct Node* root){
    if(root==NULL){
        cout<<"No data";
        return;
    }
    else{
        while(root->left != NULL){
            root = root->left;
        }
        cout<<root->data<<" is minimum";
    }
}

void findMaximum(struct Node* root){
    if(root==NULL){
        cout<<"No data";
        return;
    }
    else{
        while(root->right != NULL){
            root = root->left;
        }
        cout<<root->data<<" is maximum";
    }
}

void preOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";

    if(root->left != NULL){
        preOrder(root->left);
    }
    if(root->right != NULL){
        preOrder(root->right);
    }
}

void inOrder(struct Node* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        inOrder(root->left);
    }

    cout<<root->data<<" ";

    if(root->right != NULL){
        inOrder(root->right);
    }
}

void postOrder(struct Node* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        postOrder(root->left);
    }
    if(root->right != NULL){
        postOrder(root->right);
    }
    cout<<root->data<<" ";
}

void leafNode(struct Node* root){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
        return ;
    }
    if(root->left != NULL){
        leafNode(root->left);
    }
    if(root->right != NULL){
        leafNode(root->right);
    }
}

int main(){
    struct Node* root = createNode(7);

    insert(root, 4);
    insert(root, 9);
    insert(root, 5);
    insert(root, 8);
    insert(root, 3);
    insert(root, 10);

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    cout<<search(root, 5);
    cout<<endl;
    leafNode(root);
}