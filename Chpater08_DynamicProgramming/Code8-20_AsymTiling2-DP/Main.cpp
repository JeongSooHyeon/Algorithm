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

int cache2[101];
// 2*width ũ���� �簢���� ä��� ���Ī ����� ���� ��ȯ
int asymmetric2(int width) {
	// ���� ��� : �ʺ� 2 ������ ���
	if (width <= 2)	return 0;

	// �޸������̼�
	int& ret = cache2[width];
	if (ret != -1)	return ret;

	ret = asymmetric2(width - 2) % MOD;			// a
	ret = (ret + asymmetric2(width - 4)) % MOD;	// b
	ret = (ret + tiling(width - 3)) % MOD;	// c
	ret = (ret + tiling(width - 3)) % MOD;	// d

	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽� ��, 1<=c<=50
	cin >> c;
	int n;
	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		cin >> n;
		cout << asymmetric2(n) << endl;
	}
	return 0;
}