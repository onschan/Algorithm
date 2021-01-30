void SeletionSort(int* arr, int size) {
    int minIndex, temp;
    for (int i = 0; i < size; i++) {
        minIndex = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                min = j;
            }
        }
        /*
        # define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
        
        SWAP(arr[i],arr[index],temp);
        */
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    return;
}
