# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void QuickSort(int* arr, int size, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j) {
        while (arr[i] <= arr[pivot]) {
            i++;
        }
        while (arr[j] >= arr[pivot] && j > start) {
            j--;
        }
        if (i > j) {
            SWAP(arr[j], arr[pivot], temp);
        }
        else {
            SWAP(arr[j], arr[i], temp);
        }

        QuickSort(arr, size, start, j - 1);
        QuickSort(arr, size, j + 1, end);
    }

    return;
}

// O(NlogN)
// 이미 정렬되어있는 최악의 경우 O(N^2)
