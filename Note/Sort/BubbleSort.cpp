void BubbleSort(int* arr, int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {       
                SWAP(arr[j],arr[j+1],temp);
            }
        }
    }
    return;
}
