/*
 * 재귀함수를 이용한 DFS(깊이 우선 탐색) 구현하기
 * 2019년 07월 21일
 */

#include <stdio.h>
#include <vector>

using namespace std;

int check[9];
vector<int> vec[9];

void link(int a, int b) {
    vec[a].push_back(b);
    vec[b].push_back(a);
}

void dfs(int start) {
    if(check[start]) { // 이미 탐색했다면 끝내주자
        return;
    }

    check[start] = true; // 탐색 했음!
    printf("%d ", start);

    for(int i = 0; i < vec[start].size(); i++) {
        int a = vec[start][i]; // 탐색 중인 노드 주변에 있는 다른 노드를 가져온다.
        dfs(a); // 가져온 노드로 탐색
    }
}

int main() {
    link(1, 2);
    link(1, 3);
    link(2, 3);
    link(2, 4);
    link(2, 5);
    link(4, 8);
    link(5, 9);
    link(3, 6);
    link(3, 7);

    dfs(1);

    return 0;
}
