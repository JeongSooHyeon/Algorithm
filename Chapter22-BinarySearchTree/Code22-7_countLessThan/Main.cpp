/*
트립에서의 x보다 작은 원소의 수를 찾는 알고리즘 구현
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

// key보다 작은 키값의 수를 반환
int countLessThan(Node* root, KeyType key) {
	if (root == NULL)
		return 0;

	// root가 key보다 크거나 같으면 왼쪽 서브트리에서 key 찾기
	if (root->key >= key)
		return countLessThan(root->left, key);

	// root가 key보다 작으면
	// 왼쪽 서브트리가 있으면 왼쪽 서브트리 사이즈, 없으면 0
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}