/*
 * Stack
 * 2019년 09월 21일
 */

#include <iostream>

#define MAX 50

using namespace std;

int top = -1;
int arr[MAX] = {};

int empty() {
    return top < 0;
}

void push(int v) {
    arr[++top] = v;
}

int pop() {
    if(empty()) return -1;

    int t = arr[top];
    arr[top--] = 0;
    return t;
}

int main() {
    cout << "isEmpty? " << empty() << endl;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    pop();

    push(10);

    pop();

    cout << "isEmpty? " << empty() << endl;

    for(int i = 0; i <= top; i++) {
        cout << arr[i] << endl;
    }
}
