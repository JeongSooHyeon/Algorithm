/*
Ʈ������ ���� �� ��θ� ã�� ��� ȣ�� �˰���
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

int main() {
	int c;	// ���̽� ��
	cin >> c;
	int n;	// ������ ��, 1<=n<=100

	int walls[100][3];	// (x,y)�� �߽����� �ϴ� ������ r�� ����
	int x, y, z;	// x,y,z : ��ġ�� ũ��, 0<=x, y<=1000, 0<=i<n
	
	
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> walls[j][0] >> walls[j][1] >> walls[j][2];	// ù��° �Է��� �ܺ�

			// �Լ� ȣ��

		}
	}
}