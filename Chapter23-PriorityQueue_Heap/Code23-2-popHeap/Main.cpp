/*
정수 원소를 갖는 최대 힙에 새 원소 삭제하기
*/
#include <iostream>
#include <vector>
using namespace std;

// 정수를 담는 최대 힙 heap에서 heap[0]을 제거한다.
void pop_heap(vector<int>& heap) {
	// 힙의 맨 끝에서 값을 가져와 루트에 덮어씌운다.
	heap[0] = heap.back();
	heap.pop_back();

	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;	// 각 왼쪽, 오른쪽 자식
		// 리프에 도달한 경우
		if (left >= heap.size())
			break;
		// heap[here]가 내려갈 위치를 찾는다
		int next = here;
		if (heap[next] < heap[left])
			next = left;
		if (right < heap.size() && heap[next] < heap[right])
			next = right;
		// 두 자식이 모두 내 이하인 경우
		if (next == here)
			break;
		swap(heap[here], heap[next]);
		here = next;
	}
}