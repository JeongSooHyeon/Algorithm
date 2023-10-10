/*
�ܰ� ��ȣ �м� ������ �ذ��ϴ� ���� �ܼ��� �˰���
*/
#include <iostream>
#include <vector>
using namespace std;

int k;	// 1<=k<=5000000
int n;	// 1<=n<=50000000
vector<long long int> a;

// ���� n�� ��ȣ ����� ���� k�� �κ� ���� ����
int countRanges(const vector<long long int>& signals, int k) {
	int ret = 0;
	for (int head = 0; head < signals.size(); head++) {
		int sum = 0;
		for (int tail = head; tail < signals.size(); tail++) {
			// sum�� [head,tail] ������ ���̴�
			sum += signals[tail];
			if (sum == k)
				ret++;
			if (sum >= k)
				break;
		}
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