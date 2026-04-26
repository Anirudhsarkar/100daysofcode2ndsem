/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a Doubly Linked List node */
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) return 0;
    
    if (n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) exit(1);
        
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if (head == NULL) {
           
            head = newNode;
            tail = newNode;
        } else {
            
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
    
    
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}