#include <iostream>
#include <vector>
using namespace std;
#define MAX 10
#define INF 987654321
int n;	// 도시의 수(2 <= n <= 10)
double dist[MAX][MAX];	// 두 도시 간의 거리를 저장하는 배열
// path : 지금까지 만든 경로
// visited : 각 도시의 방문 여부
// currentLength : 지금까지 만든 경로의 길이
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	// 기저 사례 : 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료
	if (path.size() == n)
		return currentLength + dist[path.back()][path[0]];
	double ret = INF;	// 매우 큰 값으로 초기화
	// 다음 방문할 도시를 전부 시도해 본다.
	for (int next = 0; next < n; ++next) {
		if (visited[next])	// 이미 방문함
			continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		// 나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는다.
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

	vector<int> path(1, 0);	// 0번 시작
	vector<bool> visited(n, 0);
	visited[0] = true;
	cout << shortestPath(path, visited, 0) << endl;

}