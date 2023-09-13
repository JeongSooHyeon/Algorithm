#include <iostream>
using namespace std;

const int MOD = 10 * 1000 * 1000;
int cache[101][101];
// n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의 
// 정사각형을 포함하는 폴리오미노의 수를 반환한다.
int poly(int n, int first) {
	// 기저 사례 : n==first
	if (n == first)	return 1;

	// 메모이제이션
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
	int c;	// 테스트 케이스
	cin >> c;
	int n;	// 폴리오미노를 구성할 정사각형의 수 1<=n<=100
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