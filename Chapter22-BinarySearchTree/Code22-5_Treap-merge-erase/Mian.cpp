/*
Ʈ�������� ��� �߰��� Ʈ�� �ɰ��� ������ ����
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

// a�� b�� �� ���� Ʈ���̰�, max(a) < min(b)�� �� �� ���� ��ģ��
Node* merge(Node* a, Node* b) {
	// root�� ���� �ڼո� ���� �ִ� ���, root�� �ڼ��� ���� ��� ���� ó�� �ʿ� ����
	if (a == NULL) return b;
	if (b == NULL) return a;

	// a �켱������ �� ������ b�� ���ʼ���Ʈ���� ��ģ��
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}

	// b �켱������ �� ������ a�� ������ ����Ʈ���� ��ģ��
	a->setRight(merge(a->right, b));
	return a;
}

// root�� ��Ʈ�� �ϴ� Ʈ������ key�� ����� ��� Ʈ���� ��Ʈ�� ��ȯ
Node* erase(Node* root, KeyType key) {
	if (root == NULL) return root;

	// root�� ����� �� ����Ʈ���� ��ģ �� ��ȯ
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}

	// key�� root���� ������ ���ʼ���Ʈ������ �����
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	// key�� root���� ũ�� ������ ����Ʈ������ �����
	else
		root->setRight(erase(root->right, key));
	return root;
}