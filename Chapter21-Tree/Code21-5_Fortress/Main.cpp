/*
Ʈ������ ���� �� ��θ� ã�� ��� ȣ�� �˰���
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;	// ������ �� 1<=n<=100

struct TreeNode {
	vector<TreeNode*> children;
};

// ���ݱ��� ã�� ���� �� ��-�� ����� ���̸� �����Ѵ�
int longest;
// root�� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ��ȯ
int height(TreeNode* root) {
	// �� �ڽ��� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ���
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));

	// ���� �ڽ��� �ϳ��� ���ٸ� 0�� ��ȯ
	if (heights.empty())
		return 0;

	sort(heights.begin(), heights.end());

	// root�� �ֻ��� ���� �ϴ� ��θ� ���
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

	// Ʈ���� ���̴� ����Ʈ�� ������ �ִ�ġ�� 1�� ���� ���
	return heights.back() + 1;
}

// �� ��� ������ ���� �� ����� ���̸� ���
int solve(TreeNode* root) {
	longest = 0;
	// Ʈ���� ���̿� �ִ� ��-�� ��� ���� �� ū ���� ����
	int h = height(root);
	return max(longest, h);
}

// �Է� ������
int y[100], x[100], radius[100];	// x,y,z : ��ġ�� ũ��, 0<=x, y<=1000, 0<=i<n
// x^2�� ��ȯ�Ѵ�
int sqr(int x) {
	return x * x;
}
// �� ���� a,b�� �߽��� ���� �Ÿ��� ������ ��ȯ
int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}
// ���� a�� ���� b�� �����ϴ��� Ȯ���Ѵ�
bool encloses(int a, int b) {
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}
// '����'Ʈ������ parent�� child�� �θ����� Ȯ���Ѵ�
// parent�� child�� �� ���� �����ؾ� �Ѵ�.
bool isChild(int parent, int child) {
	if (!encloses(parent, child))	// parent�� child�� �����ϴ���
		return false;
	for (int i = 0; i < n; i++) {
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))	// i�� parent, child�� �ƴ�, parent�� ���Եǰ� child�� �����Ѵ�(parent�� child ���̿� �ٸ� ������ �ִ�.)
			return false;
	}
	return true;
}

// �־��� ��ȣ�� ������ ���Ե� �������� ǥ���ϴ� Ʈ���� ����
// root ������ ��Ʈ�� �ϴ� Ʈ�� ����
TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ch++) {
		// ch ������ root ������ ���������� ���ԵǾ� �ִٸ�
		// Ʈ���� ����� �ڼ� ��Ͽ� �߰�
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
	return ret;
}

int main() {
	int c;	// ���̽� ��
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x[j] >> y[j] >> radius[j];	// ù��° �Է��� �ܺ�
		}
		TreeNode* tree = getTree(0);	// 0�� ��Ʈ�� �ϴ� Ʈ�� ����
		cout << solve(tree) << endl;
	}
}