// 그래프 알고리즘

// Union-Find (합집합 찾기)
// for Disjoin-Set (서로소 집합 자료구조)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// 부모 노드를 찾는 함수
int getParent(int parent[], int current_node) {
    // 현재 노드의 부모 노드가 현재 노드와 같으면 현재 노드 반환 [종료 조건]
    if (parent[current_node] == current_node) return current_node; 
    // 현재 노드와 부모 노드가 다르다면 현재 노드의 부모노드는 현재노드의 부모노드가 가리키는 노드
    return parent[current_node] = getParent(parent, parent[current_node]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a_node, int b_node) {
    a_node = getParent(parent, a_node); // a 노드가 가리키는 부모노드
    b_node = getParent(parent, b_node); // b 노드가 가리키는 부모노드
    if (a_node < b_node) parent[b_node] = a_node;   // 더 작은 값으로 합친다
    else parent[a_node] = b_node;
}

// 같은 부모를 가지는지 확인(같은 그래프에 속하는지 확인)
bool findParent(int parent[], int a_node, int b_node) {
    a_node = getParent(parent, a_node); // a 노드가 가리키는 부모노드
    b_node = getParent(parent, b_node); // b 노드가 가리키는 부모노드
    if (a_node == b_node) return true; // 부모 노드가 같으면 1반환
    return false;   // 부모 노드가 다르면 0반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 부모노드는 연결된 노드중 가장 작은 노드의 값을 가진다.

    /* 개별적으로 독립된 그래프 생성
    노드      :   1   2   3   4   5   6   7   8   9   10
    부모노드  :   1   2   3   4   5   6   7   8   9   10
    */
    int parent[11];
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;
    }

    // 1번 노드와 2번 노드 합침(union)
    unionParent(parent, 1, 2);
    // 2번 노드와 3번 노드 합침(union)
    unionParent(parent, 2, 3);
    // 3번 노드와 4번 노드 합침(union)
    unionParent(parent, 3, 4);
    // 5번 노드와 6번 노드 합침(union)
    unionParent(parent, 5, 6);
    // 6번 노드와 7번 노드 합침(union)
    unionParent(parent, 6, 7);
    // 7번 노드와 8번 노드 합침(union)
    unionParent(parent, 7, 8);

    cout << "1과 5는 연결되어있나요?" << '\n'
        << findParent(parent, 1, 5) << '\n';

    // 1번 노드와 5번 노드 합침(union)
    unionParent(parent, 1, 5);

    cout << "1과 5는 연결되어있나요?" << '\n'
        << findParent(parent, 1, 5) << '\n';


    // 부모노드는 연결된 노드중 가장 작은 노드의 값을 가진다.

    /* 그래프의 연결상태
    노드      :   1   2   3   4   5   6   7   8   9   10
    부모노드  :   1   1   1   1   1   5   5   5   9   10
    */

    return 0;
}
