#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q;
double cache[51][101];
// connected[i][j] = 마을 i,j가 연결되어 있나 여부
// deg[i]=마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];

double search3(int here, int days) {
	// 기저 사례 : 0일째
	if (days == 0)
		return (here == q ? 1.0 : 0.0);

	// 메모이제이션
	double& ret = cache[here][days];
	if (ret > -0.5)
		return ret;

	ret = 0.0;
	for (int there = 0; there < n; there++) {
		if (connected[here][there])
			ret += search3(there, days - 1) / deg[here];
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
			memset(cache, -1, sizeof(cache));
			cin >> q;
			vector<int> path(1, p);
			cout << fixed;
			cout.precision(8);
			cout << "모스 " << search3(q, d) << ' ';
			for (int j = 0; j < t-1; j++) {
				cin >> q;
				cout << "모스 " << search3(q, d) << ' ';
			}

		cout << endl;

	}

	return 0;
}