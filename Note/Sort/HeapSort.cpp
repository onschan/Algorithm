#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#define number 9

#include <iostream>

using namespace std;

int heap[number] = { 7,6,5,8,3,5,9,1,6 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;

    for (int i = 1; i < number; i++) {
        int child = i;
        do {
            int parent = (child - 1) / 2;
            if (heap[parent] < heap[child]) {            
                SWAP(heap[parent], heap[child], temp);
            }
            child = parent;
        } while (child != 0);
    }
    
    for (int i = number - 1; i >= 0; i--) {
        SWAP(heap[0], heap[i], temp);
        int parent = 0;
        int child = 1;
        do {
            child = 2 * parent + 1;
            if (heap[child] < heap[child + 1] && child < i - 1) {
                child++;
            }
            if (heap[parent] < heap[child] && child < i) {
                SWAP(heap[parent], heap[child], temp);
            }
            parent = child;
        } while (child < i);
    }

    for (int i = 0; i < number; i++) {
        cout << heap[i] << ' ';
    }
    return 0;
}
