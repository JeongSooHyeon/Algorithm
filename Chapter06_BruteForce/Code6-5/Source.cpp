/*
6.5 소풍 문제를 해결하는 재귀 호출 코드
*/

#include <iostream>
#include <vector>
using namespace std;

int n;	// 친구 수
bool areFriends[10][10];
// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10]) {
	// 남은 학생 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	// 기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1)	return 1;
	int ret = 0;
	// 이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
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
		memset(taken, false, sizeof(taken));
		memset(areFriends, false, sizeof(areFriends));
		cin >> n >> m;	// 친구 수, 친구 쌍의 수
		for (int i = 0; i < m; ++i) {
			cin >> f1 >> f2;
			areFriends[f1][f2] = areFriends[f2][f1] = true;
		}
		cout << countPairings(taken) << endl;
	}

	return 0;
}