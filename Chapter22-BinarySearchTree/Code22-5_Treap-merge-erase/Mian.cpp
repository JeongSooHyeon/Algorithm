/*
트립에서의 노드 추가와 트립 쪼개기 연산의 구현
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

// a와 b가 두 개의 트립이고, max(a) < min(b)일 때 이 둘을 합친다
Node* merge(Node* a, Node* b) {
	// root가 한쪽 자손만 갖고 있는 경우, root가 자손이 없는 경우 별도 처리 필요 없음
	if (a == NULL) return b;
	if (b == NULL) return a;

	// a 우선순위가 더 낮으면 b의 왼쪽서브트리에 합친다
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}

	// b 우선순위가 더 낮으면 a의 오른쪽 서브트리에 합친다
	a->setRight(merge(a->right, b));
	return a;
}

// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환
Node* erase(Node* root, KeyType key) {
	if (root == NULL) return root;

	// root를 지우고 양 서브트리를 합친 뒤 반환
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}

	// key가 root보다 작으면 왼쪽서브트리에서 지우기
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	// key가 root보다 크면 오른쪽 서브트리에서 지우기
	else
		root->setRight(erase(root->right, key));
	return root;
}