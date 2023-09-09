#include <iostream>
using namespace std;

// �Է��� 32��Ʈ �ĺ� �ִ� ������ ��� ���� ���� �� �����Ƿ�
// �������� �ּ�ġ�� 64��Ʈ���� �Ѵ�.
const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];	
int cache[101][101];
// min(A[indexA],B[indexB]), max(A[indexA],B[indexB])�� �����ϴ�
// ��ģ ���� �κ� ������ �ִ� ���̸� ��ȯ�Ѵ�.
// �� indexA == indexB == -1 Ȥ�� A[indexA] != B[indexB]��� �����Ѵ�.
int jlis(int indexA, int indexB) {
	// �޸����̼�
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1)	return ret;

	// A[indexA], B[indexB]�� �̹� �����ϹǷ� 2���� �׻� �ִ�.
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	// ���� ���Ҹ� A���� ���� ���
	for (int nextA = indexA + 1; nextA < n; nextA++) {
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	}
	// ���� ���Ҹ� B���� ���� ���
	for (int nextB = indexB + 1; nextB < m; nextB++) {
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	}
	return ret;
}
int main() {
	int c;	// �׽�Ʈ ���̽��� �� 1 <= c <= 50
	cin >> c;

	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> A[j];
		}
		for (int j = 0; j < m; j++) {
			cin >> B[j];
		}
		cout << "�� " << jlis(-1, -1) - 2 << endl;
	}



	return 0;
}