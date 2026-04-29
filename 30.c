/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

void insertTerm(struct Term** poly, int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;

    if (*poly == NULL || (*poly)->exp < exp) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        struct Term* curr = *poly;
        while (curr->next != NULL && curr->next->exp > exp) {
            curr = curr->next;
        }
        if (curr->exp == exp) {
            curr->coeff += coeff;
            free(newTerm);
        } else {
            newTerm->next = curr->next;
            curr->next = newTerm;
        }
    }
}

void printPolynomial(struct Term* poly) {
    struct Term* curr = poly;
    while (curr != NULL) {
        printf("%dx^%d", curr->coeff, curr->exp);
        curr = curr->next;
        if (curr != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Term* polynomial = NULL;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertTerm(&polynomial, coeff, exp);
    }

    printPolynomial(polynomial);

    return 0;
}