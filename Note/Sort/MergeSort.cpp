#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

#define number 8
int sorted[number];

void MergeSort(int* arr, int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    // 작은 순서대로 배열에 삽입
    while (i <= middle && j <= n) {
        if (arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        }
        else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    // 남은 데이터도 삽입
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            sorted[k] = arr[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= middle; t++) {
            sorted[k] = arr[t];
            k++;
        }
    }
    // 정렬된 배열 삽입
    for (int t = m; t <= n; t++) {
        arr[t] = sorted[t];
    }
    return;
}

void MergeSort(int* arr, int m, int n) {
    // 크기가 1보다 큰 경우
    if (m < n) {
        int middle = (m + n) / 2;
        MergeSort(arr, m, middle);
        MergeSort(arr, middle + 1, n);
        MergeSort(arr, m, middle, n);
    }
    else {
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int array[number] = { 1,10,5,8,7,6,4,3 };

    MergeSort(array, 0, number - 1);

    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        cout << array[i] << " ";
    }
    return 0;
}
