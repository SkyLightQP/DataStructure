/*
 * Queue
 * 2019년 09월 26일
 */

#include <cstdio>
#include <cstdlib>

typedef struct Node {
    Node *next;
    int data;
} Node;

typedef struct Queue {
    Node *front; // 큐의 맨 앞 (출구)
    Node *rear; // 큐의 맨 뒤 (입구)
    int count; // 자료 보관 개수
} Queue;

int empty(Queue *queue) {
    return queue->count == 0;
}

void Enqueue(Queue *queue, int data) { // 큐에 자료에 보관하는 것을 Enqueue라고 함
    Node *node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;

    if(empty(queue)) {
        queue->front = node; // 큐에 아무것도 없다면 새로 넣은 데이터가 출구 쪽에 있을 것이다.
    } else {
        queue->rear->next = node; // 아니라면 입구쪽에 있을 것이다.
    }

    queue->rear = node;
    queue->count++;
}

int Dequeue(Queue *queue) { // 큐에서 자료를 빼는 것을 Dequeue라고 함
    if(empty(queue)) return 0;

    int result = 0;
    Node *node = queue->front;
    result = node->data;

    queue->front = node->next;
    queue->count--;

    free(node);

    return result;
}

int main() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->count = 0;

    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);
    Enqueue(queue, 4);
    Enqueue(queue, 5);

    while(!empty(queue)) {
        printf("%d\n", Dequeue(queue));
    }

    return 0;
}