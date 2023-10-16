/*
트리에서 가장 긴 경로를 찾는 재귀 호출 알고리즘
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
	vector<TreeNode*> children;
};

// 지금까지 찾은 가장 긴 잎-잎 경로의 길이를 저장한다
int longest;
// root를 루트로 하는 서브트리의 높이를 반환
int height(TreeNode* root) {
	// 각 자식을 루트로 하는 서브트리의 높이를 계산
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));

	// 만약 자식이 하나도 없다면 0을 반환
	if (heights.empty())
		return 0;

	sort(heights.begin(), heights.end());

	// root를 최상위 노드로 하는 경로를 고려
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

	// 트리의 높이는 서브트리 높이의 최대치에 1을 더해 계산
	return heights.back() + 1;
}

// 두 노드 사이의 가장 긴 경로의 길이를 계산
int solve(TreeNode* root) {
	longest = 0;
	// 트리의 높이와 최대 잎-잎 경로 길이 중 큰 것을 선택
	int h = height(root);
	return max(longest, h);
}

int main() {
	int c;	// 케이스 수
	cin >> c;
	int n;	// 성벽의 수, 1<=n<=100

	int walls[100][3];	// (x,y)를 중심으로 하는 반지금 r인 원형
	int x, y, z;	// x,y,z : 위치와 크기, 0<=x, y<=1000, 0<=i<n
	
	
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> walls[j][0] >> walls[j][1] >> walls[j][2];	// 첫번째 입력이 외벽

			// 함수 호출

		}
	}
}