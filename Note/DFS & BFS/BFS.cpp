#define _CRT_SECURE_NO_WARNINGS
#define number 7

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[number];
vector<int> a[number + 1];  // 인접한 노드 표시용 벡터 배열

void BFS(int start) {
    queue<int> q;   // BFS를 실행하기 위한 큐
    q.push(start);  // 시작점 q에 삽입
    visited[start] = true;  // 시작점 체크
    while (!q.empty()) {    // q에 모든 값이 사라질때까지 시행
        int x = q.front();  
        q.pop();            // 변수 x 에 q의 맨 처음을 넣어주고 삭제
        cout << x << ' '; 
        for (int i = 0; i < a[x].size(); i++) { // 현재 큐에서 꺼낸 x와 인접한 배열
            int y = a[x][i];    // 변수 y에 인접한 노드 초기화
            if (!visited[y]) {  // 방문을 하지 않은 상태라면
                q.push(y);  // q에 삽입
                visited[y] = true;  // 방문 체크
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*  트리 구현
            1
        2  ---  3
      4 - 5   6 - 7
    */

    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    BFS(1);

	return 0;
}
