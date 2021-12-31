#include <stdio.h>

int number = 8;
int sorted[8];  // 정렬 배열은 반드시 전역 변수로 선언

void merge(int a[], int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int k = start;
    // 작은 순서대로 배열에 삽입
    while(i <= middle && j <= end) {
        if(a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    // 남은 데이터도 삽입
    if(i > middle) {
        for(int t = j; t <= end; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else {
        for(int t = i; t <= middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    // 정렬된 배열을 삽입
    for(int t = start; t <= end; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int start, int end) {
    // 크기가 1보다 큰 경우
    if(start < end) {
        int middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);
        merge(a, start, middle, end);
    }
}

int main(void) {
    int array[8] = {7, 6, 5, 8, 3, 5, 9, 1};
    mergeSort(array, 0, number - 1);
    for(int i = 0; i < number; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
