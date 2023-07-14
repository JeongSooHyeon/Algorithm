#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int array[], int left, int right) {
	if (left >= right)
		return;

	int pivot = right;	// 제일 마지막에 있는 값 
	int low = left;
	int high = right - 1;

	while (true) {
		while (array[pivot] >= array[low] && low <= right)	// 왼쪽에서 피벗보다 큰 값을 찾는다
			low++;
		while (array[pivot] < array[high] && high >= left)	// 오른쪽에서 피벗보다 작은 값을 찾는다
			high--;

		if (low >= high)	// 인덱스 만나면 끝
			break;

		swap(array[low], array[high]);		// 피벗 기준 큰 값, 작은 값 스왑
	}
	swap(array[low], array[pivot]);	// 피벗의 위치 중앙으로, 피벗은 정렬된 위치

	QuickSort(array, left, low - 1);	// 왼쪽 정렬
	QuickSort(array, low + 1, right);	// 오른쪽 정렬
}