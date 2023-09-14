#include <iostream>
using namespace std;

const int INF = 987654321;
string N;

// N[a..b] ������ ���̵��� ��ȯ
int classify(int a, int b) {
	// ���� ������ �����´�.
	string M = N.substr(a, b - a + 1);
	// ù ���ڸ����� �̷���� ���ڿ��� ������ ���̵��� 1
	if (M == string(M.size(), M[0]))
		return 1;

	// ������������ �˻�
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; i++) {
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;
	}
	// ���������̰� ������ 1 Ȥ�� -1�̸� ���̵��� 2
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;

	// �� ���� ������ �����ϴ��� Ȯ��
	bool alternating = true;
	for (int i = 0; i < M.size(); i++) {
		if (M[i] != M[i % 2])
			alternating = false;
	}
	if (alternating)	return 4;	// �� ���� ������ �����ϸ� ���̵� 4
	if (progressive)	return 5;	// ������ 1 �ƴ� ���������� ���̵��� 5
	return 10;	// �� �ܴ� ��� ���̵� 10
}

int cache[10002];
// ���� N[begin..]�� �ܿ�� ��� �� ���̵��� �ּ� ���� ���
int memorize(int begin) {
	// ���� ��� : ������ ���� �������� ���
	if (begin == N.size()) return 0;

	// �޸����̼�
	int& ret = cache[begin];
	if (ret != -1) return ret;

	ret = INF;
	for (int L = 3; L <= 5; L++) {
		if (begin + L <= N.size())
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
	}
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽� 1<=c<=50
	cin >> c;
	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		cout << memorize(0) << endl;
	}


	return 0;
}