/*
6.5 소풍 문제를 해결하는 (잘못된) 재귀 호출 코드

*/

#include <iostream>
#include <vector>
using namespace std;

int n;	// 친구 수
bool areFriends[10][10];
// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10]) {
	// 기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	bool finished = true;
	for (int i = 0; i < n; ++i)
		if (!taken[i])
			finished = false;
	if (finished)
		return 1;
	int ret = 0;
	// 서로 친구인 두 학생을 찾아 짝을 지어 준다.
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
	return ret;
}

int main() {
	int c;	// 테스트 케이스 수, c <= 50
	int m;	// 친구 쌍의 수, 0 <= m <= n(n-1)/2
	cin >> c;	// 테스트 케이스

	bool taken[10] = { false };
	bool isFriend = false;
	int f1 = -1, f2 = -1;
	for (int k = 0; k < c; ++k) {
		cin >> n >> m;	// 친구 수, 친구 쌍의 수
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j)	// 초기화
				areFriends[i][j] = false;
			cin >> f1 >> f2;
			areFriends[f1][f2] = true;
		}
		cout << countPairings(taken) << endl;
	}

	return 0;
}