#define _CRT_SECURE_NO_WARNINGS
#define number 7

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[number];
vector<int> graph[number + 1];  // 인접한 노드 표시용 벡터 배열

void BFS(int start) {
    queue<int> q;   // BFS를 실행하기 위한 큐
    q.push(start);  // 시작점 q에 삽입
    visited[start] = true;  // 시작점 체크
    while (!q.empty()) {    // q에 모든 값이 사라질때까지 시행
        int current_node = q.front();  // 현재 노드 -> 큐의 맨 앞 노드
        q.pop();            // 변수 x 에 q의 맨 처음을 넣어주고 삭제
        cout << current_node << ' '; 
        for (int i = 0; i < graph[current_node].size(); i++) { // 현재 큐에서 꺼낸 현재 노드와 인접한 배열
            int next_node = graph[current_node][i];    // 다음 노드 -> 인접 노드
            if (!visited[next_node]) {  // 방문을 하지 않은 상태라면
                q.push(next_node);  // q에 삽입
                visited[next_node] = true;  // 방문 체크
            }
        }
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

    BFS(1);
	
    return 0;
}
