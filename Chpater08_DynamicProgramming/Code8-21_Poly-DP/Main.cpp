#include <iostream>
using namespace std;

const int MOD = 10 * 1000 * 1000;
int cache[101][101];
// n���� ���簢������ �̷������, �� �� �����ٿ� first���� 
// ���簢���� �����ϴ� �������̳��� ���� ��ȯ�Ѵ�.
int poly(int n, int first) {
	// ���� ��� : n==first
	if (n == first)	return 1;

	// �޸������̼�
	int& ret = cache[n][first];
	if (ret != -1) return ret;

	ret = 0;
	for (int second = 1; second <= n - first; second++) {
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;
	int n;	// �������̳븦 ������ ���簢���� �� 1<=n<=100
	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		int sum = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			sum += poly(n, j);
			sum %= MOD;
		}
		cout << sum << endl;
	}

	return 0;
}