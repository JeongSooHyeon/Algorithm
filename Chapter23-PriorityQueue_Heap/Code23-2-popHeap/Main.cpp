/*
���� ���Ҹ� ���� �ִ� ���� �� ���� �����ϱ�
*/
#include <iostream>
#include <vector>
using namespace std;

// ������ ��� �ִ� �� heap���� heap[0]�� �����Ѵ�.
void pop_heap(vector<int>& heap) {
	// ���� �� ������ ���� ������ ��Ʈ�� ������.
	heap[0] = heap.back();
	heap.pop_back();

	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;	// �� ����, ������ �ڽ�
		// ������ ������ ���
		if (left >= heap.size())
			break;
		// heap[here]�� ������ ��ġ�� ã�´�
		int next = here;
		if (heap[next] < heap[left])
			next = left;
		if (right < heap.size() && heap[next] < heap[right])
			next = right;
		// �� �ڽ��� ��� �� ������ ���
		if (next == here)
			break;
		swap(heap[here], heap[next]);
		here = next;
	}
}