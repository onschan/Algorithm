# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void SeletionSort(int* arr, int size) {
    int minIndex, temp;
    for (int i = 0; i < size; i++) {
        minIndex = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                min = j;
            }
        }
        SWAP(arr[i],arr[minIndex],temp);
    }
    return;
}
