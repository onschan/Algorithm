// Strongly Connected Component 강한 결합 요소 (SCC)
// 그래프 안에서 강하게 결합된 정점 집합
// '같은 SCC에 속하는 두 정점은 서로 도달이 가능하다.'
// O(V+E)

// 타잔 알고리즘(Tarjan's Algorithm)
// 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10001

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

//DFS는 총 정점의 갯수만큼 실행된다.
int DFS(int current_node) {
    d[current_node] = ++id; // 노드마다 고유한 번호 할당(맨처음 부모로 설정된 값)
    s.push(current_node);   // 스택에 자기 자신을 삽입

    int parent = d[current_node];
    for (int i = 0; i < a[current_node].size(); i++) {
        int next_node = a[current_node][i];
        // 방문하지 않은 이웃
        if (d[next_node] == 0) parent = min(parent, DFS(next_node));
        // 처리중인 이웃
        else if (!finished[next_node]) parent = min(parent, d[next_node]);
    }
    // 부모노드가 자기자신인 경우 (본인으로 돌아온 경우)
    if (parent == d[current_node]) {
        vector<int> scc;
        while (true) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == current_node) break;
        }
        SCC.push_back(scc);
    }
    // 자신의 부모 값을 반환
    return parent;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 11;
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[4].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(6);
    a[8].push_back(5);
    a[8].push_back(9);
    a[9].push_back(10);
    a[10].push_back(11);
    a[11].push_back(3);
    a[11].push_back(8);
    for (int i = 1; i <= v; i++) {
        if (d[i] == 0) DFS(i);
    }

    cout << "SCC의 갯수 : " << SCC.size() << endl;
    for (int i = 0; i < SCC.size(); i++) {
        cout << i + 1 << "번째 SCC : ";
        for (int j = 0; j < SCC[i].size(); j++) {
            cout << SCC[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
