bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    int count[1000] = {0};
    for (int i=0; i<targetSize; i++) {
        count[target[i]]++;
        count[arr[i]]--;
    }

    for (int j=0; j<1000; j++) {
        if (count[j]!=0) return false;
    }
    
    return true;
}