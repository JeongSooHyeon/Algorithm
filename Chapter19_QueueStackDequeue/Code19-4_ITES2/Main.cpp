/*
�ܰ� ��ȣ �м� ������ �ذ��ϴ� ����ȭ�� �˰���
*/
#include <iostream>
#include <vector>
using namespace std;

int k;	// 1<=k<=5000000
int n;	// 1<=n<=50000000

// ���� n�� ��ȣ ����� ���� k�� �κ� ���� ����
int countRanges(const vector<long long int>& signals, int k) {
	int ret = 0, tail = 0, rangeSum = signals[0];
	for (int head = 0; head < signals.size(); head++) {

		// rangeSum�� k�̻��� ������ ������ ���� ������ tail�� �ű��
		while (rangeSum < k && tail + 1 < signals.size())
			rangeSum += signals[++tail];

		if (rangeSum == k)
			ret++;

		// signals[head]�� ���� �������� ������
		rangeSum -= signals[head];
	}
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;

	long long int outSig = 1983;
	long long int tmp = pow(2, 32);
	int signal = -1;

	for (int i = 0; i < c; i++) {
		vector<long long int> a;
		cin >> k >> n;

		for (int j = 1; j < n; j++) {
			outSig = (outSig * 214013 + 2531011) % tmp;	// �ܺ� ��ȣ 
			signal = outSig % 10000 + 1;	// ��ó��
			a.push_back(signal);
		}

		cout << countRanges(a, k) << endl;

	}



	return 0;
}