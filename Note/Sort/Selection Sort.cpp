void SeletionSort(int* arr, int size) {
    int i, min, temp;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        /*
        # define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
        
        SWAP(arr[i],arr[index],temp);
        */
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    return;
}
