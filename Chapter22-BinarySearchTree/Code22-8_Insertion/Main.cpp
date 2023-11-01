#include <iostream>
using namespace std;

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

typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root, KeyType key) {
	if (root == NULL)
		return NodePair(NULL, NULL);
	// ��Ʈ�� key �̸��̸� ������ ����Ʈ���� �ɰ���
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}

	// ��Ʈ�� key �̻��̸� ���� ����Ʈ���� �ɰ���
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
Node* insert(Node* root, Node* node) {
	if (root == NULL)
		return node;

	// node�� ��Ʈ�� ��ü�ؾ� �Ѵ�. �ش� ����Ʈ���� ������ �߶�
	// ���� �ڼ����� �Ѵ�.
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}
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


// �� �迭�� ����(1<=n<=50000)
// shifted[i] = A[i]�� �������� �� ĭ �����̴°�?
int n, shifted[50000];
int A[50000];
// n, shifted[]�� ���� A[]�� ���� �����Ѵ�.
void solve() {
	// 1~N������ ���ڸ� ��� �����ϴ� Ʈ���� �����
	Node* candidates = NULL;
	for (int i = 0; i < n; i++) {
		candidates = insert(candidates, new Node(i + 1));
	}

	// �ڿ������� A[]�� ä��������
	for (int i = n - 1; i >= 0; i--) {
		// �ĺ� �� �� ������ ū ���� larger�� �ִ�.
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		A[i] = k->key;
		candidates = erase(candidates, k->key);
	}
}

int main() {
	int c;	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> shifted[j];
		}
		solve();
		// ���
		for (int i = 0; i < n; i++) {
			cout << A[i] << ' ';
		}
		cout << endl;

	}



	return 0;
}