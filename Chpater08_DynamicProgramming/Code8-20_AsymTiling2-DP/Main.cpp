#include <iostream>
using namespace std;

const int MOD = 1000000007;
int cache[101];
// 2 * width 크기의 사각형을 채우는 방법의 수 MOD로 나눈 나머지를 반환
int tiling(int width) {
	// 기저 사례 : width가 1 이하일 때
	if (width <= 1)	return 1;

	// 메모제이션
	int& ret = cache[width];
	if (ret != -1)	return ret;

	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int cache2[101];
// 2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환
int asymmetric2(int width) {
	// 기저 사례 : 너비가 2 이하인 경우
	if (width <= 2)	return 0;

	// 메모이제이션
	int& ret = cache2[width];
	if (ret != -1)	return ret;

	ret = asymmetric2(width - 2) % MOD;			// a
	ret = (ret + asymmetric2(width - 4)) % MOD;	// b
	ret = (ret + tiling(width - 3)) % MOD;	// c
	ret = (ret + tiling(width - 3)) % MOD;	// d

	return ret;
}

int main() {
	int c;	// 테스트 케이스 수, 1<=c<=50
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