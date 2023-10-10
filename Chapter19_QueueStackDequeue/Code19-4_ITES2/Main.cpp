/*
외계 신호 분석 문제를 해결하는 최적화된 알고리즘
*/
#include <iostream>
#include <vector>
using namespace std;

int k;	// 1<=k<=5000000
int n;	// 1<=n<=50000000

// 길이 n인 신호 기록의 합이 k인 부분 수열 갯수
int countRanges(const vector<long long int>& signals, int k) {
	int ret = 0, tail = 0, rangeSum = signals[0];
	for (int head = 0; head < signals.size(); head++) {

		// rangeSum이 k이상인 최초의 구간을 만날 때까지 tail을 옮긴다
		while (rangeSum < k && tail + 1 < signals.size())
			rangeSum += signals[++tail];

		if (rangeSum == k)
			ret++;

		// signals[head]는 이제 구간에서 빠진다
		rangeSum -= signals[head];
	}
	return ret;
}

int main() {
	int c;	// 테스트 케이스
	cin >> c;

	long long int outSig = 1983;
	long long int tmp = pow(2, 32);
	int signal = -1;

	for (int i = 0; i < c; i++) {
		vector<long long int> a;
		cin >> k >> n;

		for (int j = 1; j < n; j++) {
			outSig = (outSig * 214013 + 2531011) % tmp;	// 외부 신호 
			signal = outSig % 10000 + 1;	// 전처리
			a.push_back(signal);
		}

		cout << countRanges(a, k) << endl;

	}



	return 0;
}