# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void InsertionSort(int* arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        int j = i;
        while (arr[j] > arr[j + 1]) {
            SWAP(arr[j], arr[j + 1], temp);
            j--;
        }
    }
    return;
}
