/*
트리 순회 순서 변경 문제를 해결하는 재귀 호출 코드
*/
#include <iostream>
#include <vector>
using namespace std;

struct BinaryTree {
	string label;	// 저장할 자료
	BinaryTree* left;;	// 왼쪽 자식을 가리키는 포인터
	BinaryTree* Right;;	// 오른쪽 자식을 가리키는 포인터
};

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

// 트리의 전위탑색 결과와 중위탐색 결과가 주어질 때 후위탐색 결과를 출력
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	// 트리에 포함된 노드의 수
	const int n = preorder.size();

	// 기저 사례 : 텅 빈 트리면 곧장 종료
	if (preorder.empty())
		return;

	// 이 트리의 루트는 전위 탐색 결과로부터 곧장 알 수 있다.
	const int root = preorder[0];

	// 이 트리의 왼쪽 서브트리의 크기는 중위 탐색 결과에서 루트의 위치를 찾아서 알 수 있다.
	const int l = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	// 오른쪽 서브트리의 크기는 n에서 왼쪽 서브트리와 루트를 빼면 알 수 있다.
	const int r = n - 1 - l;

	// 왼쪽과 오른쪽 서브트리의 순회 결과를 출력
	printPostOrder(slice(preorder, 1, l + 1), slice(inorder, 0, l));
	printPostOrder(slice(preorder, l + 1, n), slice(inorder, l + 1, n));

	// 후위 순회이므로 루트를 가장 마지막에 출력한다.
	cout << root << ' ';
}

int main() {
	int c;	// 테스트 케이스
	cin >> c;

	int n;	// 1<=n<=100, 트리에 포함된 노드의 수

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