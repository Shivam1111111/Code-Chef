#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right; 
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root,int data){
    if(root == NULL){
        printf("No value found");
        return NULL;
    }
    if(root->data == data){
        return root->data;
    }
    if(root->data < data){
        return search(root->right,data);
    }
    if(root->data > data){
        return search(root->left,data);
    }
    return root;
}


void inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        inOrder(root->left);
    }
    printf("%d\n", root->data);
    if(root->right != NULL)
    {
        inOrder(root->right);
    }
}



int leaf_count(struct Node *root, int count){
    if(root == NULL) {
        return count;
    }

    if(root->left == NULL && root->right == NULL) {

        // printf("%d",root->data);
        // cout<<root->data<<endl;
        return ++count;
    }

    if(root->left) {
        count = leaf_count(root->left, count);
    }

    if(root->right) {
        count = leaf_count(root->right, count);
    }

    return count;
}

int main()
{
    struct Node *root = createNode(20);
    // struct Node *root;
    insert(root, 100);
    insert(root, 25);
    insert(root, 30);
    insert(root, 5);
    // insert(root, 100);
    insert(root, 7);

    inOrder(root);
    // printf("%d",search(root,7));
    printf("\n No. of leaf : %d ",leaf_count(root, 0));
    return 0;
}