/*
Ʈ�� ��ȸ ���� ���� ������ �ذ��ϴ� ��� ȣ�� �ڵ�
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

// Ʈ���� ����ž�� ����� ����Ž�� ����� �־��� �� ����Ž�� ����� ���
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	// ���� ��� : �� �� Ʈ���� ���� ����
	if (preorder.empty())
		return;

	// Ʈ���� ���Ե� ����� ��
	const int N = preorder.size();	

	// �� Ʈ���� ��Ʈ�� ���� Ž�� ����κ��� ���� �� �� �ִ�.
	const int root = preorder[0];

	// �� Ʈ���� ���� ����Ʈ���� ũ��� ���� Ž�� ������� ��Ʈ�� ��ġ�� ã�Ƽ� �� �� �ִ�.
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	// ������ ����Ʈ���� ũ��� N���� ���� ����Ʈ���� ��Ʈ�� ���� �� �� �ִ�.
	const int R = N - 1 - L;

	// ���ʰ� ������ ����Ʈ���� ��ȸ ����� ���
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));	// ����
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));	// ������

	// ���� ��ȸ�̹Ƿ� ��Ʈ�� ���� �������� ���
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

		printPostOrder(preorder, inorder);
	}
}