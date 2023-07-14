#include <iostream>
using namespace std;

void MergeSort(int array[], int left, int right) {
	if (left < right) {						// 재귀 함수 종료 조건
		int mid = (left + right) / 2;
		MergeSort(array, left, mid);		// 분할
		MergeSort(array, mid + 1, right);	// 분할
		Merge(array, left, mid, right);		// 병합
	}
}

void Merge(int array[], int left, int mid, int right) {
	int leftIdx = left;
	int rightIdx = mid + 1;

	int* sortArr = new int[right + 1];
	int sortIdx = left;

	while (leftIdx <= mid && rightIdx <= right) {	// 왼쪽 오른쪽 둘 중 하나가 바닥 나기 전까지
		if (array[leftIdx] <= array[rightIdx])
			sortArr[sortIdx++] = array[leftIdx++];
		else
			sortArr[sortIdx++] = array[rightIdx++];
	}

	if (leftIdx > mid) {	// 왼쪽이 먼저 바닥나면 오른쪽 값을 넘겨줌
		while (rightIdx <= right)
			sortArr[sortIdx++] = array[rightIdx++];
	}
	else {
		while (leftIdx <= mid)	// 오른쪽 먼저 바닥나면 왼쪽 값을 넣어줌
			sortArr[sortIdx++] = array[leftIdx++];
	}

	for (int i = left; i <= right; i++)	// 배열 복사
		array[i] = sortArr[i];

	delete[] sortArr;	
}