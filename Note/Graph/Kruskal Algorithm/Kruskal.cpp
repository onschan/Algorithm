// MST (최소비용 신장 트리)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int current_node) {
    if (parent[current_node] == current_node) return current_node; 
    return parent[current_node] = getParent(parent, parent[current_node]);
}

void unionParent(int parent[], int a_node, int b_node) {
    a_node = getParent(parent, a_node);
    b_node = getParent(parent, b_node);
    if (a_node < b_node) parent[b_node] = a_node;
    else parent[a_node] = b_node;
}

bool findParent(int parent[], int a_node, int b_node) {
    a_node = getParent(parent, a_node); 
    b_node = getParent(parent, b_node);
    if (a_node == b_node) return true;
    return false;
}

// 간선 클래스 선언
class Edge {
public:
    int node[2];
    int distance;
    Edge(int a_node, int b_node, int distance) {
        this->node[0] = a_node;
        this->node[1] = b_node;
        this->distance = distance;
    }
    bool operator <(Edge& edge) {
        return this->distance < edge.distance;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int nodes = 7;
    const int edges = 11;

    // 가중치(거리) 와 노드의 연결상태가 표시된 그래프 생성
    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));

    // 간선의 비용을 기준으로 오름차순 정렬
    sort(v.begin(), v.end());

    // 각 정점이 포함된 그래프가 어디인지 저장
    int parent[nodes+1];  // Union-Find 사용
    for (int i = 1; i <= nodes; i++) {
        parent[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        //사이클이 발생하지 않는 경우 그래프에 포함
        if (!findParent(parent, v[i].node[0], v[i].node[1])) {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0], v[i].node[1]);
        }
    }

    cout << sum;

    return 0;
}
