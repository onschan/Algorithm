#define _CRT_SECURE_NO_WARNINGS
#define number 7

#include <iostream>
#include <vector>

using namespace std;

int visited[number];
vector<int> graph[number + 1];  // 인접한 노드 표시용 벡터 배열

void DFS(int current_node) {
    if (visited[current_node]) return; // 현재 노드가 방문한 상태라면 함수 종료
    visited[current_node] = true;   // 종료되지 않았다면(방문하지 않았다면) 방문 표시
    cout << current_node << ' ';
    for (int i = 0; i < graph[current_node].size(); i++) {
        int next_node = graph[current_node][i];  // 인접 노드 -> 다음 노드
        DFS(next_node);     // 다음 노드에 대하여 재귀함수 호출
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*  그래프 구현
            1
        2  ---  3
      4 - 5   6 - 7
    */

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[2].push_back(4);
    graph[4].push_back(2);

    graph[2].push_back(5);
    graph[5].push_back(2);

    graph[3].push_back(6);
    graph[6].push_back(3);

    graph[3].push_back(7);
    graph[7].push_back(3);

    graph[4].push_back(5);
    graph[5].push_back(4);

    graph[6].push_back(7);
    graph[7].push_back(6);

    DFS(1);

    return 0;
}
