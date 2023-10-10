/*
외계 신호 분석 문제를 해결하는 온라인 알고리즘
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
//		outSig = (outSig * 214013 + 2531011) % tmp;	// 외부 신호 
//		signal = outSig % 10000 + 1;	// 전처리
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

// 길이 n인 신호 기록의 합이 k인 부분 수열 갯수
int countRanges(int k, int n) {
	RNG rng;	// 신호값을 생성하는 난수 생성기
	queue<int> range;	// 현재 구간에 들어 있는 숫자들을 저장하는 큐
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		// 구간에 숫자를 추가
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		// 구간의 합이 k를 초과하는 동안 구간에서 숫자를 뺀다
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
	int c;	// 테스트 케이스
	cin >> c;
	int k;	// 1<=k<=5000000
	int n;	// 1<=n<=50000000


	for (int i = 0; i < c; i++) {
		cin >> k >> n;

		cout << countRanges(k, n) << endl;
	}

	return 0;
}