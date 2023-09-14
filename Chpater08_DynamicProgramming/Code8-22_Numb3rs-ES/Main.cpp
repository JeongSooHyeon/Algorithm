#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q;
// connected[i][j] = 마을 i,j가 연결되어 있나 여부
// deg[i]=마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];
double search(vector<int>& path) {
	// 기저 사례 : d일이 지난 경우
	if (path.size() == d + 1) {
		// 이 시나리오가 q에서 끝나지 않는다면 무효
		if (path.back() != q)
			return 0.0;

		// path의 출현 확률을 계산한다
		double ret = 1.0;
		for (int i = 0; i + 1 < path.size(); ++i) {
			ret /= deg[path[i]];
		}
		return ret;
	}

	double ret = 0;
	// 경로의 다음 위치를 결정한다.
	for (int there = 0; there < n; there++) {
		if (connected[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	}
	return ret;
}

int main() {
	int c;	// 테스트 케이스
	cin >> c;

	//int n;	// 지도에 포함된 마을의 수, 2<=n<=50
	//int d;	// 탈출 후 지금까지 지난 일수, 1<=d<=100
	//int p;	// 교도소가 있는 마을 번호, 0<=p<n
	// int a[51][51];	// 마을을 잇는 산길
	int t;	// 확률을 계산할 마을의 수, 0<=t<n;
	//int q;	// t개의 정수로 확률을 계산할 마을의 번호, 0<=q<n

	for (int i = 0; i < c; i++) {
		cin >> n >> d >> p;
		memset(deg, 0, sizeof(deg));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> connected[j][k];
				if (connected[j][k] == 1)
					deg[j]++;
			}
		}
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> q;
			vector<int> path(1, p);
			cout << fixed;
			cout.precision(8);
			cout << search(path) << ' ';
		}
		cout << endl;

	}

	return 0;
}