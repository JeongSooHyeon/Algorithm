#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i]+1 << ' ';
	cout << endl;
}

void allCombination(int n, vector<int>& v, vector<bool>& visited) {
	if (v.size() == n)
		Print(v);
	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;
		v.push_back(i);
		visited[i] = true;
		allCombination(n, v, visited);
		visited[i] = false;
		v.pop_back();
	}

}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	vector<bool> visited(n, false);

	allCombination(n, v, visited);
}