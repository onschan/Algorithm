#define _CRT_SECURE_NO_WARNINGS
#define number 15

#include <iostream>

using namespace std;

// 하나의 노드 정보를 선언
typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

// 전위 순회
void preorder(treePointer ptr) {
    if (ptr) {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

// 중위 순회
void inorder(treePointer ptr) {
    if (ptr) {
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

// 후위 순회
void postorder(treePointer ptr) {
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 그래프 생성(이진 트리)
    node nodes[number + 1];
    for (int i = 1; i <= number; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    for (int i = 1; i <= number; i++) {
        if (i % 2 == 0) {
            nodes[i / 2].leftChild = &nodes[i];
        }
        else {
            nodes[i / 2].rightChild = &nodes[i];
        }
    }
    
    preorder(&nodes[1]);
    cout << '\n';
    inorder(&nodes[1]);
    cout << '\n';
    postorder(&nodes[1]);

    return 0;
}
