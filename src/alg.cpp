// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int sc = 0;
  for (int i = 0; i < len; i++) {
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
  int min = 0, max = len - 1;
  while (min != max) {
    if (arr[min] + arr[max] == value) {
      sc++;
      max--;
    } else {
      if (arr[min] + arr[max] > value) {
        max--;
      } else {
        min++;
      }
    }
  }
  return sc;
}
int countPairs3(int *arr, int len, int value) {
  int mid;
  int left = 0;
  int right = len - 1;
  int sc;
  int k = 0;
  while (left < right) {
    mid = left + (right - left) / 2;
    while (true) {
      sc = 1;
      if (arr[mid] + arr[mid + sc] >= value) {
        while (arr[mid] + arr[mid + sc] == value) {
          k++;
          sc++; 
        }
        right = mid;
        break;       
      }
      if (arr[mid] + arr[mid - sc] <= value) {
        while (arr[mid] + arr[mid - sc] == value) {
          k++;
          sc--;
          left = mid;
        }
        break;
      }
    }
  }
  return k;
}
