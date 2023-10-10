/*
�ܰ� ��ȣ �м� ������ �ذ��ϴ� �¶��� �˰���
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//class RNG {
//private:
//	long long int outSig = 1983;
//	long long int tmp = pow(2, 32);
//	int signal = -1;
//public:
//	int next() {
//		outSig = (outSig * 214013 + 2531011) % tmp;	// �ܺ� ��ȣ 
//		signal = outSig % 10000 + 1;	// ��ó��
//
//		return signal;
//	}
//};

class RNG {
private:
	unsigned seed;
public:
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 124013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

// ���� n�� ��ȣ ����� ���� k�� �κ� ���� ����
int countRanges(int k, int n) {
	RNG rng;	// ��ȣ���� �����ϴ� ���� ������
	queue<int> range;	// ���� ������ ��� �ִ� ���ڵ��� �����ϴ� ť
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		// ������ ���ڸ� �߰�
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		// ������ ���� k�� �ʰ��ϴ� ���� �������� ���ڸ� ����
		while (rangeSum > k) {
			rangeSum -= range.front();
			range.pop();
		}

		if (rangeSum == k)
			ret++;
	}
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;
	int k;	// 1<=k<=5000000
	int n;	// 1<=n<=50000000


	for (int i = 0; i < c; i++) {
		cin >> k >> n;

		cout << countRanges(k, n) << endl;
	}

	return 0;
}