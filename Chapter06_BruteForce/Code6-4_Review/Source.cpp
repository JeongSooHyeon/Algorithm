#include <iostream>
#include <vector>
using namespace std;

int n;	// 2 <= n <= 10

int makePair(bool areFriends[10][10], bool madenPair[10]) {
	int firstFreind = -1;
	for (int i = 0; i < n; ++i) {
		if (!madenPair[i]) {
			firstFreind = i;	// 아직 짝이 없는 친구
			break;
		}
	}
	// 기저 사례 : 모두 짝을 이뤘을 때
	if (firstFreind == -1)
		return 1;
	int cnt = 0;	// 짝지어줄 수 있는 방법의 수

	for (int i = firstFreind+1; i < n; ++i) {
		if (!madenPair[i] && areFriends[firstFreind][i]) {	// 친구 쌍을 찾음
			madenPair[firstFreind] = true;	// 친구 쌍 지어주기
			madenPair[i] = true;	// 친구 쌍 지어주기
			cnt += makePair(areFriends, madenPair);
			madenPair[firstFreind] = false;	
			madenPair[i] = false;	
		}
	}
	return cnt;
}
int main() {
	int c;	// c <= 50
	int m;	// 0 <= <= n(n-1)/2
	cin >> c;

	int f1=-1, f2=-1;
	for (int i = 0; i < c; ++i) {
		bool madenPair[10] = { false, };
		bool areFriends[10][10] = { false, };	// 서로 친구인지
		cin >> n >> m;
		for (int j = 0; j < m; ++j) {
			cin >> f1 >> f2;
			areFriends[f1][f2] = true;
			areFriends[f2][f1] = true;
		}
		cout << makePair(areFriends, madenPair) << endl;
	}
}