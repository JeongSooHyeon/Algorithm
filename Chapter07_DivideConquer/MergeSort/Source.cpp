#include <iostream>
using namespace std;

void MergeSort(int array[], int left, int right) {
	if (left < right) {						// ��� �Լ� ���� ����
		int mid = (left + right) / 2;
		MergeSort(array, left, mid);		// ����
		MergeSort(array, mid + 1, right);	// ����
		Merge(array, left, mid, right);		// ����
	}
}

void Merge(int array[], int left, int mid, int right) {
	int leftIdx = left;
	int rightIdx = mid + 1;

	int* sortArr = new int[right + 1];
	int sortIdx = left;

	while (leftIdx <= mid && rightIdx <= right) {	// ���� ������ �� �� �ϳ��� �ٴ� ���� ������
		if (array[leftIdx] <= array[rightIdx])
			sortArr[sortIdx++] = array[leftIdx++];
		else
			sortArr[sortIdx++] = array[rightIdx++];
	}

	if (leftIdx > mid) {	// ������ ���� �ٴڳ��� ������ ���� �Ѱ���
		while (rightIdx <= right)
			sortArr[sortIdx++] = array[rightIdx++];
	}
	else {
		while (leftIdx <= mid)	// ������ ���� �ٴڳ��� ���� ���� �־���
			sortArr[sortIdx++] = array[leftIdx++];
	}

	for (int i = left; i <= right; i++)	// �迭 ����
		array[i] = sortArr[i];

	delete[] sortArr;	
}