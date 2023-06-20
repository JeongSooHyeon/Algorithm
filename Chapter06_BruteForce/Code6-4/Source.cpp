/*
6.4 소풍
*/

#include <iostream>
#include <vector>
using namespace std;


int n;
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
	int c;	// 테스트 케이스 수, c <= 50
	int n;	// 학생의 수, 2 <= n <= 10
	int m;	// 친구 쌍의 수, 0 <= m <= n(n-1)/2
	vector<pair<int, int>> v;	// 서로 친구인 학생 쌍
	int f1, f2;
	vector<int> madenV;

	cin >> c;

	for (int i = 0; i < c; ++i) {
		cin >> n >> m;	// 학생 수, 친구 쌍의 수
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
	if (idx >= m || idx >= m) {	// 범위..
		//printPair(madenV);
		cnt++;
		return;
	}
	int f1 = friendPr[idx].first;	// 친구1
	int f2 = friendPr[idx].second;	// 친구2
	for (int i = 0; i < madenV.size(); ++i) {	// 이미 쌍을 이뤘으면
		if (madenV[i] == f1 || madenV[i]==f2) {
			return;
		}
	}
	for (int i = idx; i < m; ++i) {
		madenV.push_back(f1);	// 친구 쌍 추가
		madenV.push_back(f2);	// 친구 쌍 추가
		makePair(m, friendPr, madenV, i+1);	// 다음 친구 쌍
		madenV.pop_back();
		madenV.pop_back();
	}
}
int main() {
	int c;	// 테스트 케이스 수, c <= 50
	int n;	// 학생의 수, 2 <= n <= 10
	int m;	// 친구 쌍의 수, 0 <= m <= n(n-1)/2
	vector<pair<int, int>> v;	// 서로 친구인 학생 쌍
	int f1, f2;
	vector<int> madenV;

	cin >> c;

	for (int i = 0; i < c; ++i) {
		cin >> n >> m;	// 학생 수, 친구 쌍의 수
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