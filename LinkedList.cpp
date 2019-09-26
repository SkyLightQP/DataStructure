/*
 * LinkedList (연결리스트)
 * 2019년 09월 26일
 */

#include <cstdio>
#include <cstdlib>

typedef struct _node {
    struct _node *next;
    int data;
} node;

int main() {
    node *head = (node*) malloc(sizeof(node));

    node *node1 = (node*) malloc(sizeof(node));

    head->next = node1;
    node1->data=  1;

    node *node2 = (node*) malloc(sizeof(node));

    node1->next = node2;
    node2->data = 2;

    node *node3 = (node*) malloc(sizeof(node));

    node2->next = node3;
    node3->data = 3;


    node3->next = NULL;


    node *now = head->next;
    while(now != NULL) {
        printf("%d\n", now->data);
        now = now->next;
    }

    free(head); free(node1); free(node2);

    return 0;
}