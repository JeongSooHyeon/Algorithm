#include <iostream>
#include <vector>
using namespace std;
#define MAX 10
#define INF 987654321
int n;	// ������ ��(2 <= n <= 10)
double dist[MAX][MAX];	// �� ���� ���� �Ÿ��� �����ϴ� �迭
// path : ���ݱ��� ���� ���
// visited : �� ������ �湮 ����
// currentLength : ���ݱ��� ���� ����� ����
// ������ ���õ��� ��� �湮�ϴ� ��ε� �� ���� ª�� ���� ���̸� ��ȯ

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	// ���� ��� : ��� ���ø� �� �湮���� ���� ���� ���÷� ���ư��� ����
	if (path.size() == n)
		return currentLength + dist[path.back()][path[0]];
	double ret = INF;	// �ſ� ū ������ �ʱ�ȭ
	// ���� �湮�� ���ø� ���� �õ��� ����.
	for (int next = 0; next < n; ++next) {
		if (visited[next])	// �̹� �湮��
			continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		// ������ ��θ� ��� ȣ���� ���� �ϼ��ϰ� ���� ª�� ����� ���̸� ��´�.
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
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