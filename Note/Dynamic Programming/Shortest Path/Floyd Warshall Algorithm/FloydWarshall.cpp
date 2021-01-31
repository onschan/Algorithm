// 플로이드 와샬 알고리즘 : 모든 정점에서 모든 정점으로의 최단 경로 구하는 알고리즘
// 2차원 배열에 i > j 로 가는 최단 경로 저장

#define _CRT_SECURE_NO_WARNINGS
#define number 4
#define INF 1000000000

#include <iostream>

using namespace std;

// 자료 배열 초기화
int a[number][number] = {
    {0,5,INF,8},
    {7,0,9,INF},
    {2,INF,0,4},
    {INF,INF,3,0}
};

void floydWarshall() {
    // 결과 그래프 초기화
    int d[number][number];

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            d[i][j] = a[i][j];
        }
    }

    // k = 거쳐가는 노드
    for (int k = 0; k < number; k++) {
        // i = 출발 노드
        for (int i = 0; i < number; i++) {
            // j = 도착 노드
            for (int j = 0; j < number; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    floydWarshall();

    return 0;
}
