/*
6.5 ��ǳ ������ �ذ��ϴ� ��� ȣ�� �ڵ�
*/

#include <iostream>
#include <vector>
using namespace std;

int n;	// ģ�� ��
bool areFriends[10][10];
// taken[i] = i��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false
int countPairings(bool taken[10]) {
	// ���� �л� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	// ���� ��� : ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	if (firstFree == -1)	return 1;
	int ret = 0;
	// �� �л��� ¦���� �л��� �����Ѵ�.
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
	int c;	// �׽�Ʈ ���̽� ��, c <= 50
	int m;	// ģ�� ���� ��, 0 <= m <= n(n-1)/2
	cin >> c;	// �׽�Ʈ ���̽�

	bool taken[10] = { false };
	bool isFriend = false;
	int f1 = -1, f2 = -1;
	for (int k = 0; k < c; ++k) {
		memset(taken, false, sizeof(taken));
		memset(areFriends, false, sizeof(areFriends));
		cin >> n >> m;	// ģ�� ��, ģ�� ���� ��
		for (int i = 0; i < m; ++i) {
			cin >> f1 >> f2;
			areFriends[f1][f2] = areFriends[f2][f1] = true;
		}
		cout << countPairings(taken) << endl;
	}

	return 0;
}