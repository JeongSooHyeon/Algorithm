#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
// A[] : ����ȭ�ؾ� �� ����, ������ ����
// pSum[] : A[]�� �κ����� �����Ѵ�. pSum[i]�� A[0]..A[i]�� ��
// pSqSum[]: A[]������ �κ����� �����Ѵ�. pSqSum[i]�� A[0]^2�� ��
int n;	// ������ ���� 1 <= n <= 100
int A[101], pSum[101], pSqSum[101];
// A�� �����ϰ� �� �κ����� ����Ѵ�.
void precalc() {
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

// A[lo]..A[hi] ������ �ϳ��� ���ڷ� ǥ���� �� �ּ� ���� ���� ���
int minError(int lo, int hi) {
	// �κ����� �̿��� A[lo]~A[hi]������ ���� ���Ѵ�.
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
	// ����� �ݿø��� ������ �� ������ ǥ���Ѵ�.
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	// sum(A[i]-m)^2�� ������ ����� �κ� ������ ǥ��
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}

int cache[101][11];
int quantize(int from, int parts) {
	// ���� ��� : ��� ���ڸ� �� ����ȭ ���� ��
	if (from == n)	return 0;
	// ���� ��� : ���ڴ� ���� ���Ҵµ� �� ���� �� ���� �� ���� ū ���� ��ȯ
	if (parts == 0)	return INF;

	int& ret = cache[from][parts];
	if (ret != -1)	return ret;
	ret = INF;
	// ������ ���̸� ��ȭ���� ���� �ּ�ġ�� ã�´�.
	for (int partSize = 1; from + partSize <= n; partSize++)
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));

	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽� 1 <= c <= 50
	int s;	// ����� ������ �� 1 <= s <= 10
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> s;
		for (int j = 0; j < n; j++)
			cin >> A[j];
		memset(cache, -1, sizeof(cache));
		precalc();
		cout << quantize(0, s) << endl;

	}

	return 0;
}