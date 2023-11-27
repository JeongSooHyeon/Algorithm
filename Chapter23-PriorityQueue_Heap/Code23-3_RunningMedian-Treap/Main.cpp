/*
��ȭ�ϴ� �߰� �� ������ Ʈ���� ����� Ǯ��
*/
#include <iostream>
#include <vector>
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
class RNG {
public :
	KeyType next() {
		return 1;
	}
};
Node* insert(Node* root, Node* n) {}
Node* kth(Node* root, int n);

// rng�� �����ϴ� ù n���� ������ ������ �߰��ϸ� �߰� ���� ���Ѵ�.
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