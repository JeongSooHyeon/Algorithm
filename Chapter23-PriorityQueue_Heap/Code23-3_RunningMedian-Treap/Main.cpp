/*
변화하는 중간 값 문제를 트립을 사용해 풀기
*/
#include <iostream>
#include <vector>
using namespace std;

typedef int KeyType;
// 트립의 한 노드를 저장한다.
struct Node {
	// 노드에 저장된 원소
	KeyType key;

	// 이 노드의 우선순위
	// 이 노드를 루트로 하는 서브트리의 크기
	int priority, size;

	// 두 자식 노드의 포인터
	Node* left, * right;

	// 생성자에서 난수 우선순위를 생성하고, size롸 left/right를 초기화한다
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {

	}

	void setLeft(Node* newLeft) {
		left = newLeft;
		calcSize();
	}
	void setRight(Node* newRight) {
		right = newRight;
		calcSize();
	}

	// size 멤버를 갱신
	void calcSize() {
		size = 1;
		if (left)
			size += left->size;
		if (right)
			size += right->size;
	}
};
class RNG {
public :
	KeyType next() {
		return 1;
	}
};
Node* insert(Node* root, Node* n) {}
Node* kth(Node* root, int n);

// rng가 생성하는 첫 n개의 난수를 수열에 추가하며 중간 값을 구한다.
int runningMedian(int n, RNG rng) {
	Node* root = NULL;
	int ret = 0;
	for (int cnt = 1; cnt <= n; cnt++) {
		root = insert(root, new Node(rng.next()));
		int median = kth(root, (cnt + 1) / 2)->key;
		ret = (ret + median) % 20090711;
	}
	return ret;
}