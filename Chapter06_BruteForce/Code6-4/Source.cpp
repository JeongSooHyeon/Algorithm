/*
6.5 ��ǳ ������ �ذ��ϴ� (�߸���) ��� ȣ�� �ڵ�

*/

#include <iostream>
#include <vector>
using namespace std;

int n;	// ģ�� ��
bool areFriends[10][10];
// taken[i] = i��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false
int countPairings(bool taken[10]) {
	// ���� ��� : ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	bool finished = true;
	for (int i = 0; i < n; ++i)
		if (!taken[i])
			finished = false;
	if (finished)
		return 1;
	int ret = 0;
	// ���� ģ���� �� �л��� ã�� ¦�� ���� �ش�.
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
	int c;	// �׽�Ʈ ���̽� ��, c <= 50
	int m;	// ģ�� ���� ��, 0 <= m <= n(n-1)/2
	cin >> c;	// �׽�Ʈ ���̽�

	bool taken[10] = { false };
	bool isFriend = false;
	int f1 = -1, f2 = -1;
	for (int k = 0; k < c; ++k) {
		cin >> n >> m;	// ģ�� ��, ģ�� ���� ��
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j)	// �ʱ�ȭ
				areFriends[i][j] = false;
			cin >> f1 >> f2;
			areFriends[f1][f2] = true;
		}
		cout << countPairings(taken) << endl;
	}

	return 0;
}