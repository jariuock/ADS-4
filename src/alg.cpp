int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;
    for (int i = 0; i < right; i++) {
        for (int j = right - 1; j > left; j--) {
            if (arr[j] > value)
                right--;
            if (arr[i] + arr[j] == value)
                count++;
        }
        left++;
    }
    return count;
}

int binarySearchCount(int* arr, int left, int right, int target) {
    int l = left, r = right, first = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            first = mid;
            r = mid - 1;
        }
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (first == -1)
        return 0;
    l = first;
    r = right;
    int last = first;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            last = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return last - first + 1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int num = binarySearchCount(arr, i + 1, len - 1, target);
        count += num;
    }
    return count;
}
