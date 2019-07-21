/*
 * Queue 자료구조를 활용한 BFS(너비 우선 탐색) 구현하기
 * 2019년 07월 21일
 */

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int check[10];
vector<int> vec[10];

void link(int a, int b) {
    vec[a].push_back(b);
    vec[b].push_back(a);
}

void bfs(int start) {
    queue<int> q;
    q.push(start); // 시작점 노드를 Queue에 넣는다.
    check[start] = true; // 시작점 탐색 완료

    while (!q.empty()) { // Queue가 비어있으면 탐색 완료
        int front = q.front(); // 제일 앞에 있는 노드를 가져온다.

        q.pop(); // 노드를 꺼내주고
        printf("%d ", front); // 출력한다.

        for (int i = 0; i < vec[front].size(); i++) {
            int a = vec[front][i];  // 꺼낸 노드 주변에 인접한 모든 노드를 가져온다.

            if (!check[a]) { // 그 노드들을 탐색하지 않았다면,
                q.push(a); // Queue에 넣어주고
                check[a] = true; // 탐색 완료
            }
        }
    }
}

int main() {
    link(1, 2);
    link(1, 3);
    link(2, 4);
    link(2, 5);
    link(4, 8);
    link(5, 9);
    link(9, 10);
    link(3, 6);
    link(3, 7);

    bfs(1);

    return 0;
}

