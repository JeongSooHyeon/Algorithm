#include <iostream>
using namespace std;

void quickSort(int array[], int start, int end) {
	if (start >= end) {	// ���Ұ� 1���� ��
		return;
	}

	int pivot = start;
	int low = pivot + 1;	// ���� ��� ����
	int high = end;		// ������ ��� ����
	int temp;

	while (low <= high) {	// �����Ͱ� ������ ������ �ݺ�
		while (low <= end && array[low] <= array[pivot])
			low++;
		while (high > start && array[high] >= array[pivot])
			high--;

		if (low > high) {	// ������, pivot�� ������ pivot���� ���� ����, ������ ū ���鸸 �����ϰ� ��
			temp = array[high];
			array[high] = array[pivot];
			array[pivot] = temp;
		}
		else {			// i��°�� j��° ����
			temp = array[low];
			array[low] = array[high];
			array[high] = temp;
		}
	}

	// ���� ���, pivot�� �߽����� ����
	quickSort(array, start, high - 1);
	quickSort(array, high + 1, end);
}