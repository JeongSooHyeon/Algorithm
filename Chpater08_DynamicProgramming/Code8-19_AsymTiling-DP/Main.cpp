#include <iostream>
using namespace std;

const int MOD = 1000000007;
int cache[101];
// 2 * width ũ���� �簢���� ä��� ����� �� MOD�� ���� �������� ��ȯ
int tiling(int width) {
	// ���� ��� : width�� 1 ������ ��
	if (width <= 1)	return 1;

	// �޸����̼�
	int& ret = cache[width];
	if (ret != -1)	return ret;

	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

// 2*width ũ���� �簢���� ä��� ���Ī ����� ���� ��ȯ
int asymmetric(int width) {
	if (width % 2 == 1)	// Ȧ��
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽� ��, 1<=c<=50
	cin >> c;
	int n;
	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << asymmetric(n) << endl;
	}
	return 0;
}