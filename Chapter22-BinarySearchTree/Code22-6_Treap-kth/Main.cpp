/*
트립에서의 k번째 원소를 찾는 알고리즘의 구현
*/
#include <iostream>
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

Node* kth(Node* root, int k) {
	// 왼쪽 서브트리의 크기를 우선 계산
	int leftSize = 0;
	if (root->left != NULL)
		leftSize = root->left->size;

	// k번째 원소가 왼쪽 서브트리에 있다.
	if (k <= leftSize)
		return kth(root->left, k);

	// root가 k번째 원소
	if (k == leftSize + 1)
		return root;

	// k번째 원소가 오른쪽 서브트리에 있다.
	return kth(root->right, k - leftSize - 1);
}