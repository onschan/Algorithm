#define _CRT_SECURE_NO_WARNINGS
#define NUMBER 12

#include <iostream>

using namespace std;

int a[] = { 1,3, 5, 7, 9, 11, 14, 15, 18, 19, 25, 28 };
int want = 7;

int binarySearch(int start, int end, int target) {
    if (start > end) return -1; // 탐색 실패
    int mid = (start + end) / 2;
    if (a[mid] == target) return mid;   // 탐색 성공
    else if (a[mid] > target) return binarySearch(start, mid - 1, target);
    else return binarySearch(mid + 1, end, target);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = binarySearch(0, NUMBER - 1, want);
    if (result != -1)
        cout << result << "번 인덱스에서 찾았습니다.";

    return 0;
}
