#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q;
double cache[51][101];
// connected[i][j] = ���� i,j�� ����Ǿ� �ֳ� ����
// deg[i]=���� i�� ����� ������ ����
int connected[51][51], deg[51];

// days��°�� here�� ������ ���� �ִٰ� ����,
// ������ ���� q�� ������ ���� ���� ���Ǻ� Ȯ�� ��ȯ
double search2(int here, int days) {
	// ���� ��� : d���� ���� ���
	if (days == d)
		return (here == q ? 1.0 : 0.0);

	// �޸������̼�
	double& ret = cache[here][days];
	if (ret > -0.5)
		return ret;

	ret = 0.0;
	for (int there = 0; there < n; there++) {
		if (connected[here][there])
			ret += search2(there, days + 1) / deg[here];
	}
	return ret;
}

int main() {
	int c;	// �׽�Ʈ ���̽�
	cin >> c;

	//int n;	// ������ ���Ե� ������ ��, 2<=n<=50
	//int d;	// Ż�� �� ���ݱ��� ���� �ϼ�, 1<=d<=100
	//int p;	// �����Ұ� �ִ� ���� ��ȣ, 0<=p<n
	// int a[51][51];	// ������ �մ� ���
	int t;	// Ȯ���� ����� ������ ��, 0<=t<n;
	//int q;	// t���� ������ Ȯ���� ����� ������ ��ȣ, 0<=q<n

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
			memset(cache, -1, sizeof(cache));
			cin >> q;
			cout << fixed;
			cout.precision(8);
			cout << search2(p,0) << ' ';
		}
		cout << endl;

	}

	return 0;
}