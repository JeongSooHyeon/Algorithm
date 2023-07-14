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

	int pivot = right;	// ���� �������� �ִ� �� 
	int low = left;
	int high = right - 1;

	while (true) {
		while (array[pivot] >= array[low] && low <= right)	// ���ʿ��� �ǹ����� ū ���� ã�´�
			low++;
		while (array[pivot] < array[high] && high >= left)	// �����ʿ��� �ǹ����� ���� ���� ã�´�
			high--;

		if (low >= high)	// �ε��� ������ ��
			break;

		swap(array[low], array[high]);		// �ǹ� ���� ū ��, ���� �� ����
	}
	swap(array[low], array[pivot]);	// �ǹ��� ��ġ �߾�����, �ǹ��� ���ĵ� ��ġ

	QuickSort(array, left, low - 1);	// ���� ����
	QuickSort(array, low + 1, right);	// ������ ����
}