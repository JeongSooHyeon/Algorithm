/*
- Ʈ���� ��带 ǥ���ϴ� ��ü�� ����
- Ʈ���� ��ȸ�ϸ� ��� ��忡 ���Ե� ���� ���
- ��ȸ�� �̿��� Ʈ���� ���̸� ����ϱ�
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	string label;	// ������ �ڷ�
	TreeNode* parent;	// �θ� ��带 ����Ű�� ������
	vector<TreeNode*> children;	// �ڼ� ������ ����Ű�� �������� �迭
 };

// Ʈ�� ��ȸ
void printLables(TreeNode* root) {
	// ��Ʈ�� ����� �� ���
	cout << root->label << endl;
	// �� �ڼյ��� ��Ʈ�� �ϴ� ����Ʈ���� ���Ե� ������ ��������� ���
	for (int i = 0; i < root->children.size(); i++)
		printLables(root->children[i]);
}

// root�� ��Ʈ�� �ϴ� Ʈ���� ���̸� ���Ѵ�
int height(TreeNode* root) {
	int h = 0; 
	for (int i = 0; i < root->children.size(); i++)
		h = max(h, 1 + height(root->children[i]));
	return h;
}