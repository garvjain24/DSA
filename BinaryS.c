#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *Insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = Insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = Insert(root->left, value);
    }
    return root;
}

struct Node *min(struct Node *node){
    struct Node *current = node;
    while(current && current->left !=NULL){
        current=current->left;
    }
    return current;

}
struct Node *delete(struct Node *root,int value){
    if(root==NULL){
        return root;
    }
    if(value<root->data){
        root->left= delete(root->left ,value);
    }
    else if (value>root->data){
        root->right=delete(root->right,value);
    }
    else{
        if(root->left==NULL){
            struct Node * temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            struct Node *temp=root->left;
            free(root);
            return temp ;
        }
        struct Node* temp=min(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
}
void preOrder(struct Node *root){
    if(root!=NULL){
    printf(" %d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
    }
}
void inOrder(struct Node *root){
    if(root!=NULL){
    inOrder(root->left);
    printf(" %d ",root->data);
    inOrder(root->right);
    }
}
void postOrder(struct Node *root){
    if(root!=NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ",root->data);
    }
}
int main()
{
    struct Node *root = NULL;

    root = Insert(root, 50);
    root = Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);

    printf("Binary Search Tree (Inorder Traversal): ");
    inOrder(root);
    printf("\n");

    printf("Deleting 20 from the tree\n");
    root = delete(root, 20);

    printf("Binary Search Tree (Inorder Traversal) after deletion: ");
    inOrder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}