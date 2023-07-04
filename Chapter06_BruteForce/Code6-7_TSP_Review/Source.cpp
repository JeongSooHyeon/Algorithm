#include <iostream>
#include <vector>
using namespace std;

#define MAX 10
#define INF 987654321
int n;	// 도시의 수(2 <= n <= 10)
double dist[MAX][MAX];	// 두 도시 간의 거리를 저장하는 배열


double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {

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

	vector<int> path(1, 0);	// 0번 시작
	vector<bool> visited(n, 0);
	visited[0] = true;
	cout << shortestPath(path, visited, 0) << endl;

}