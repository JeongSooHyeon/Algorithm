/*
Ʈ�������� k��° ���Ҹ� ã�� �˰����� ����
*/
#include <iostream>
using namespace std;

typedef int KeyType;
// Ʈ���� �� ��带 �����Ѵ�.
struct Node {
	// ��忡 ����� ����
	KeyType key;

	// �� ����� �켱����
	// �� ��带 ��Ʈ�� �ϴ� ����Ʈ���� ũ��
	int priority, size;

	// �� �ڽ� ����� ������
	Node* left, * right;

	// �����ڿ��� ���� �켱������ �����ϰ�, size�� left/right�� �ʱ�ȭ�Ѵ�
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

	// size ����� ����
	void calcSize() {
		size = 1;
		if (left)
			size += left->size;
		if (right)
			size += right->size;
	}
};

Node* kth(Node* root, int k) {
	// ���� ����Ʈ���� ũ�⸦ �켱 ���
	int leftSize = 0;
	if (root->left != NULL)
		leftSize = root->left->size;

	// k��° ���Ұ� ���� ����Ʈ���� �ִ�.
	if (k <= leftSize)
		return kth(root->left, k);

	// root�� k��° ����
	if (k == leftSize + 1)
		return root;

	// k��° ���Ұ� ������ ����Ʈ���� �ִ�.
	return kth(root->right, k - leftSize - 1);
}