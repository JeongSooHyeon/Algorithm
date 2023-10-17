/*
트리에서 가장 긴 경로를 찾는 재귀 호출 알고리즘
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;	// 성벽의 수 1<=n<=100

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

// 입력 데이터
int y[100], x[100], radius[100];	// x,y,z : 위치와 크기, 0<=x, y<=1000, 0<=i<n
// x^2을 반환한다
int sqr(int x) {
	return x * x;
}
// 두 성벽 a,b의 중심점 간의 거리의 제곱을 반환
int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}
// 성벽 a가 성벽 b를 포함하는지 확인한다
bool encloses(int a, int b) {
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}
// '성벽'트리에서 parent가 child의 부모인지 확인한다
// parent는 child를 꼭 직접 포함해야 한다.
bool isChild(int parent, int child) {
	if (!encloses(parent, child))	// parent가 child를 포함하는지
		return false;
	for (int i = 0; i < n; i++) {
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))	// i는 parent, child가 아님, parent에 포함되고 child를 포함한다(parent와 child 사이에 다른 성벽이 있다.)
			return false;
	}
	return true;
}

// 주어진 번호의 성벽에 포함된 구역들을 표현하는 트리를 생성
// root 성벽을 루트로 하는 트리 생성
TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ch++) {
		// ch 성벽이 root 성벽에 직접적으로 포함되어 있다면
		// 트리를 만들고 자손 목록에 추가
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
	return ret;
}

int main() {
	int c;	// 케이스 수
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x[j] >> y[j] >> radius[j];	// 첫번째 입력이 외벽
		}
		TreeNode* tree = getTree(0);	// 0을 루트로 하는 트리 생성
		cout << solve(tree) << endl;
	}
}