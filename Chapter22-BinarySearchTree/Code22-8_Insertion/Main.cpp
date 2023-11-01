#include <iostream>
using namespace std;

/*
트립에서의 k번째 원소를 찾는 알고리즘의 구현
*/
#include <iostream>
using namespace std;

typedef int KeyType;
// 트립의 한 노드를 저장한다.
struct Node {
	// 노드에 저장된 원소
	KeyType key;

	// 이 노드의 우선순위
	// 이 노드를 루트로 하는 서브트리의 크기
	int priority, size;

	// 두 자식 노드의 포인터
	Node* left, * right;

	// 생성자에서 난수 우선순위를 생성하고, size롸 left/right를 초기화한다
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

	// size 멤버를 갱신
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
	// 루트가 key 미만이면 오른쪽 서브트리를 쪼갠다
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}

	// 루트가 key 이상이면 왼쪽 서브트리를 쪼갠다
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
Node* insert(Node* root, Node* node) {
	if (root == NULL)
		return node;

	// node가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라
	// 각각 자손으로 한다.
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
// a와 b가 두 개의 트립이고, max(a) < min(b)일 때 이 둘을 합친다
Node* merge(Node* a, Node* b) {
	// root가 한쪽 자손만 갖고 있는 경우, root가 자손이 없는 경우 별도 처리 필요 없음
	if (a == NULL) return b;
	if (b == NULL) return a;

	// a 우선순위가 더 낮으면 b의 왼쪽서브트리에 합친다
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}

	// b 우선순위가 더 낮으면 a의 오른쪽 서브트리에 합친다
	a->setRight(merge(a->right, b));
	return a;
}
// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환
Node* erase(Node* root, KeyType key) {
	if (root == NULL) return root;

	// root를 지우고 양 서브트리를 합친 뒤 반환
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}

	// key가 root보다 작으면 왼쪽서브트리에서 지우기
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	// key가 root보다 크면 오른쪽 서브트리에서 지우기
	else
		root->setRight(erase(root->right, key));
	return root;
}
Node* kth(Node* root, int k) {
	// 왼쪽 서브트리의 크기를 우선 계산
	int leftSize = 0;
	if (root->left != NULL)
		leftSize = root->left->size;

	// k번째 원소가 왼쪽 서브트리에 있다.
	if (k <= leftSize)
		return kth(root->left, k);

	// root가 k번째 원소
	if (k == leftSize + 1)
		return root;

	// k번째 원소가 오른쪽 서브트리에 있다.
	return kth(root->right, k - leftSize - 1);
}


// 원 배열의 길이(1<=n<=50000)
// shifted[i] = A[i]가 왼쪽으로 몇 칸 움직이는가?
int n, shifted[50000];
int A[50000];
// n, shifted[]를 보고 A[]에 값을 저장한다.
void solve() {
	// 1~N까지의 숫자를 모두 저장하는 트립을 만든다
	Node* candidates = NULL;
	for (int i = 0; i < n; i++) {
		candidates = insert(candidates, new Node(i + 1));
	}

	// 뒤에서부터 A[]를 채워나간다
	for (int i = n - 1; i >= 0; i--) {
		// 후보 중 이 수보다 큰 수가 larger개 있다.
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
		// 출력
		for (int i = 0; i < n; i++) {
			cout << A[i] << ' ';
		}
		cout << endl;

	}



	return 0;
}