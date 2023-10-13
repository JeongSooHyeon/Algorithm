/*
Ʈ�� ��ȸ ���� ���� ������ �ذ��ϴ� ��� ȣ�� �ڵ�
*/
#include <iostream>
#include <vector>
using namespace std;

struct BinaryTree {
	string label;	// ������ �ڷ�
	BinaryTree* left;;	// ���� �ڽ��� ����Ű�� ������
	BinaryTree* Right;;	// ������ �ڽ��� ����Ű�� ������
};

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

// Ʈ���� ����ž�� ����� ����Ž�� ����� �־��� �� ����Ž�� ����� ���
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	// Ʈ���� ���Ե� ����� ��
	const int n = preorder.size();

	// ���� ��� : �� �� Ʈ���� ���� ����
	if (preorder.empty())
		return;

	// �� Ʈ���� ��Ʈ�� ���� Ž�� ����κ��� ���� �� �� �ִ�.
	const int root = preorder[0];

	// �� Ʈ���� ���� ����Ʈ���� ũ��� ���� Ž�� ������� ��Ʈ�� ��ġ�� ã�Ƽ� �� �� �ִ�.
	const int l = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	// ������ ����Ʈ���� ũ��� n���� ���� ����Ʈ���� ��Ʈ�� ���� �� �� �ִ�.
	const int r = n - 1 - l;

	// ���ʰ� ������ ����Ʈ���� ��ȸ ����� ���
	printPostOrder(slice(preorder, 1, l + 1), slice(inorder, 0, l));
	printPostOrder(slice(preorder, l + 1, n), slice(inorder, l + 1, n));

	// ���� ��ȸ�̹Ƿ� ��Ʈ�� ���� �������� ����Ѵ�.
	cout << root << ' ';
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;

	int n;	// 1<=n<=100, Ʈ���� ���Ե� ����� ��

	for (int i = 0; i < c; i++) {
		cin >> n;
		vector<int> preorder(n);
		vector<int> inorder(n);
		for (int j = 0; j < n; j++) {
			cin >> preorder[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> inorder[j];
		}


	}
}