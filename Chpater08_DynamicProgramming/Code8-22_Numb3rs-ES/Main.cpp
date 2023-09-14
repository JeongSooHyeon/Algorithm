#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q;
// connected[i][j] = ���� i,j�� ����Ǿ� �ֳ� ����
// deg[i]=���� i�� ����� ������ ����
int connected[51][51], deg[51];
double search(vector<int>& path) {
	// ���� ��� : d���� ���� ���
	if (path.size() == d + 1) {
		// �� �ó������� q���� ������ �ʴ´ٸ� ��ȿ
		if (path.back() != q)
			return 0.0;

		// path�� ���� Ȯ���� ����Ѵ�
		double ret = 1.0;
		for (int i = 0; i + 1 < path.size(); ++i) {
			ret /= deg[path[i]];
		}
		return ret;
	}

	double ret = 0;
	// ����� ���� ��ġ�� �����Ѵ�.
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