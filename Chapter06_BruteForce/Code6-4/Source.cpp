/*
6.4 ��ǳ
*/

#include <iostream>
#include <vector>
using namespace std;


int n;
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
	for(int i=0; i<n; ++i)
		for(int j=0; j<n;++j)
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
	return ret;
}


int main() {
	int c;	// �׽�Ʈ ���̽� ��, c <= 50
	int n;	// �л��� ��, 2 <= n <= 10
	int m;	// ģ�� ���� ��, 0 <= m <= n(n-1)/2
	vector<pair<int, int>> v;	// ���� ģ���� �л� ��
	int f1, f2;
	vector<int> madenV;

	cin >> c;

	for (int i = 0; i < c; ++i) {
		cin >> n >> m;	// �л� ��, ģ�� ���� ��
		for (int j = 0; j < m; ++j) {
			cnt = 0;
			cin >> f1 >> f2;
			v.push_back(pair<int, int>(f1, f2));
		}
		makePair(m, v, madenV, 0);
		cout << "cnt : " << cnt << endl;

	}


	return 0;
}



int cnt = 0;
void printPair(vector<int>& v) {
	cout << v.size() / 2;
}
void makePair(int m, vector<pair<int, int>>& friendPr, vector<int>& madenV, int idx) {
	if (idx >= m || idx >= m) {	// ����..
		//printPair(madenV);
		cnt++;
		return;
	}
	int f1 = friendPr[idx].first;	// ģ��1
	int f2 = friendPr[idx].second;	// ģ��2
	for (int i = 0; i < madenV.size(); ++i) {	// �̹� ���� �̷�����
		if (madenV[i] == f1 || madenV[i]==f2) {
			return;
		}
	}
	for (int i = idx; i < m; ++i) {
		madenV.push_back(f1);	// ģ�� �� �߰�
		madenV.push_back(f2);	// ģ�� �� �߰�
		makePair(m, friendPr, madenV, i+1);	// ���� ģ�� ��
		madenV.pop_back();
		madenV.pop_back();
	}
}
int main() {
	int c;	// �׽�Ʈ ���̽� ��, c <= 50
	int n;	// �л��� ��, 2 <= n <= 10
	int m;	// ģ�� ���� ��, 0 <= m <= n(n-1)/2
	vector<pair<int, int>> v;	// ���� ģ���� �л� ��
	int f1, f2;
	vector<int> madenV;

	cin >> c;

	for (int i = 0; i < c; ++i) {
		cin >> n >> m;	// �л� ��, ģ�� ���� ��
		for (int j = 0; j < m; ++j) {
			cnt = 0;
			cin >> f1 >> f2;
			v.push_back(pair<int, int>(f1, f2));			
		}
		makePair(m, v, madenV, 0);
		cout << "cnt : " <<  cnt << endl;

	}


	return 0;
}