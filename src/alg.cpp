// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int sc = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        sc++;
      }
    }
  }
  return sc;
}
int countPairs2(int *arr, int len, int value) {
  int sc = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        sc++;
      }
    }
  }
  return sc;
}
int countPairs3(int *arr, int len, int value) {
  int mid;
  int sc;
  int k = 0;
  for (int i = 0; i < len; i++) {
    int left = i;
    int right = len;
    while (left < right-1) {
      mid = (left + right) / 2;
      if (arr[i] + arr[mid] == value) {
        k++;
        sc = 1;
        while (arr[mid] == arr[mid + sc] && (mid + sc) < right) {
          k++;
          sc++; 
        }
        sc = 1;
        while (arr[mid] == arr[mid - sc] && (mid - sc) > left) {
          k++;
          sc++;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        right = mid;
      }
      if (arr[i] + arr[mid] < value) {
        left = mid;
      }
    }
  }
  return k;
}
