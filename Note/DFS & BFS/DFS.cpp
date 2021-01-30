#define _CRT_SECURE_NO_WARNINGS
#define number 7

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int visited[number];
vector<int> graph[number + 1];  // 인접한 노드 표시용 벡터 배열

void DFS(int start) {
    stack<int> s;   // DFS 용 스택 생성
    s.push(start);  // 스택에 start 값 삽입
    visited[start] = true;  // 방문 표시
    cout << start << ' ';
    while (!s.empty()) {    // 스택이 빌때까지 반복
        int current_node = s.top(); // 현재 노드 -> 스택의 최상단노드
        s.pop();    // 스택 최상단 pop
        for (int i = 0; i < graph[current_node].size(); i++) {  // 현재 노드의 인접노드 확인
            int next_node = graph[current_node][i];     // 다음 노드 -> 인접 노드
            if (visited[next_node] == false) {  // 인접 노드를 방문하지 않았다면
                cout << next_node << ' ';   
                s.push(current_node);       // pop 했던 현재 노드 삽입 (먼저 실행!)
                s.push(next_node);          // 다음 노드 삽입
                visited[next_node] = true;  // 방문 표시
                break;
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

    DFS(1);

	return 0;
}
