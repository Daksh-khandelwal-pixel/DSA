#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->right = NULL;
    newNode->left= NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value){
    if(root == NULL){
        return createNode(value);
    }
    
    if(value<root->data){
        root->left = insert(root->left, value);
    }
    else if(value>root->data){
        root->right = insert(root->right, value);
    }
    return root;
}

struct Node *search(struct Node *root, int key) {
    // Base case: tree is empty or key is found at current node
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is smaller than root's data -> search left subtree
    if (key < root->data) {
        return search(root->left, key);
    }

    // Key is larger than root's data -> search right subtree
    return search(root->right, key);
}

int findMax(struct Node *root){
    if(root==NULL){
        printf("Empty");
        return -1;
    }
    struct Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int findMin(struct Node *root){
    if(root==NULL){
        printf("Empty");
        return -1;
    }
    struct Node *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

// 5. Traversals
void inorder(struct Node *root){   // Left -> Root -> Right (Sorted)
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// 5. Traversals
void preorder(struct Node *root){   // Root -> Left -> Right (Sorted)
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 5. Traversals
void postorder(struct Node *root){   // Left -> Right -> Root (Sorted)
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main(){
    struct Node *root = NULL;

    // Insert values: 50, 30, 70, 20, 40, 60, 80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root);   // 20 30 40 50 60 70 80

    printf("\nPreorder: ");
    preorder(root);  // 50 30 20 40 70 60 80

    printf("\nPostorder: ");
    postorder(root); // 20 40 30 60 80 70 50

    printf("\nMin value: %d", findMin(root)); // 20
    printf("\nMax value: %d\n", findMax(root)); // 80

    if(search(root, 40) != NULL){
        printf("40 Found!\n");
    } else {
        printf("40 Not Found!\n");
    }

    return 0;
}

