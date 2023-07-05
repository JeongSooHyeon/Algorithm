#include <iostream>
#include <vector>
using namespace std;

#define MAX 10
#define INF 987654321
int n;	// ������ ��(2 <= n <= 10)
double dist[MAX][MAX];	// �� ���� ���� �Ÿ��� �����ϴ� �迭


double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	// ���� ��� : ��� ��θ� �� ��������? ó������ ���ƿ�
	if (path.size() == n)
		return currentLength + dist[path.back()][path[0]];

	int ret = INF;
	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;
		int here = path.back();
		path.push_back(i);
		visited[i] = true;
		ret = min(ret, (int)shortestPath(path, visited, currentLength + dist[here][i]));
		visited[i] = false;
		path.pop_back();
	}
}

int main() {
	cin >> n;
	memset(dist, -1, sizeof(dist));
	int val;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> val;
			dist[i][j] = val;
		}
	}

	vector<int> path(1, 0);	// 0�� ����
	vector<bool> visited(n, 0);
	visited[0] = true;
	cout << shortestPath(path, visited, 0) << endl;

}