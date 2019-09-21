/*
 * 다익스트라 알고리즘
 * 2019년 09월 21일
 */

#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int V, E, START;

vector<vector<int>> graph;

vector<int> dijk() {
    vector<int> check(V, false);
    vector<int> dist(V, INF);
    dist[START - 1] = 0; // 자기 자신과의 거리는 0이다.

    while(1) {
        int i = INF; // 최단거리
        int N = -1; // 방문한 노드

        for(int j = 0; j < V; j++) {
            if(!check[j] && i > dist[j]) {
                i = dist[j];
                N = j;
            }
        }

        if(i == INF) break; // 다른 노드의 최단 거리가 모두 INF이면 나가자

        check[N] = true; // 방문

        for(int j = 0; j < V; j++) {
            if(check[j]) continue; // 이미 방문 했다면 패스

            // dist[목표정점] = min(dist[목표정점], dist[현재정점] + 가중치)
            int d = dist[N] + graph[N][j]; // N을 통해서 가는 인접 노드들의 거리를 저장
            if(dist[j] > d) dist[j] = d;
        }

    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> START;

    graph.assign(V, vector<int>(V, INF));

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u - 1][v - 1] = w;
    }

    vector<int> dist = dijk();

    for(int i = 0; i < dist.size(); i++) {
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}
