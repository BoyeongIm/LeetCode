bool canThreePartsEqualSum(int* arr, int arrSize) {
    int totalSum = 0;
    for (int i=0; i<arrSize; i++) {
        totalSum += arr[i];
    }
    if (totalSum % 3 != 0) return false;
    int count = 0;
    int part = 0;
    for (int i=0; i<arrSize; i++) {
        part += arr[i];
        if (part == totalSum/3) {
            part = 0;
            count += 1;
        }
    }

    if (count==3) return true;
    else return false;
}