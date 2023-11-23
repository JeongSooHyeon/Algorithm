/*
���� ���Ҹ� ���� �ִ� ���� �� ���� �����ϱ�
*/
#include <iostream>
#include <vector>
using namespace std;

// ������ ��� �ִ� �� heap�� �� ���� newValue�� �����Ѵ�
void push_heap(vector<int>& heap, int newValue) {
	// ���� �� ���� newValue�� ����
	heap.push_back(newValue);
	// ���� newValue�� ��ġ
	int idx = heap.size() - 1;
	// ��Ʈ�� �����ϰų� newValue �̻��� ���Ҹ� ���� ������ ���� ������
	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}