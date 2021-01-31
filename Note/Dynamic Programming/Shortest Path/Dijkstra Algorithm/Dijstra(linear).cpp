// 선형탐색 다익스트라
// 시간 복잡도 O(N^2)
// 간선이 단 하나라도 모든 정점을 두번씩 돌아야함

#define _CRT_SECURE_NO_WARNINGS
#define number 6
#define INF 1000000000

#include <iostream>

using namespace std;

// 전체 그래프 초기화
int a[number][number] = {
    {0,2,5,1,INF,INF},
    {2,0,3,2,INF,INF},
    {5,3,0,3,1,5},
    {1,2,3,0,1,INF},
    {INF,INF,1,1,0,2},
    {INF,INF,5,INF,2,0},
};

bool visited[number];   // 방문한 노드
int dist[number];   // 최단 거리

// 가장 최소 거리를 가지는 정점을 반환
int getSmallIndex() {
    int min = INF;
    int index = 0;
    for (int i = 0; i < number; i++) {
        if (dist[i] < min && !visited[i]) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// 다익스트라를 수행하는 함수
void dijkstra(int start) {
    for (int i = 0; i < number; i++) {
        dist[i] = a[start][i];
    }
    visited[start] = true;
    for (int i = 0; i < number - 2; i++) {
        int current = getSmallIndex();
        visited[current] = true;
        for (int j = 0; j < 6; j++) {
            if (!visited[j]) {
                if (dist[current] + a[current][j] < dist[j]) {
                    dist[j] = dist[current] + a[current][j];
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dijkstra(0);

    for (int i = 0; i < number; i++) {
        cout << dist[i] << ' ';
    }

    return 0;
}
