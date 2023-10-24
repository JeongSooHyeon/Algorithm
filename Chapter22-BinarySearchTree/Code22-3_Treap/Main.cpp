/*
Ʈ���� ��带 ǥ���ϴ� ��ü�� ����
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

