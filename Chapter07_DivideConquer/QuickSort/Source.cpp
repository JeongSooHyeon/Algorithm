#include <iostream>
using namespace std;

void quickSort(int array[], int start, int end) {
	if (start >= end) {	// 원소가 1개일 때
		return;
	}

	int pivot = start;
	int low = pivot + 1;	// 왼쪽 출발 지점
	int high = end;		// 오른쪽 출발 지점
	int temp;

	while (low <= high) {	// 포인터가 엇갈릴 때까지 반복
		while (low <= end && array[low] <= array[pivot])
			low++;
		while (high > start && array[high] >= array[pivot])
			high--;

		if (low > high) {	// 엇갈림, pivot의 좌측은 pivot보다 작은 값들, 우측은 큰 값들만 존재하게 됨
			temp = array[high];
			array[high] = array[pivot];
			array[pivot] = temp;
		}
		else {			// i번째와 j번째 스왑
			temp = array[low];
			array[low] = array[high];
			array[high] = temp;
		}
	}

	// 분할 계산, pivot을 중심으로 나눔
	quickSort(array, start, high - 1);
	quickSort(array, high + 1, end);
}