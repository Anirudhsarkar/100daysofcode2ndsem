/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insertBST(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);
    return root;
}

struct Node* buildTree(int arr[], int n) {
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            root = insertBST(root, arr[i]);
        }
    }
    return root;
}

int searchBST(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int key;
    scanf("%d", &key);

    if (searchBST(root, key))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}