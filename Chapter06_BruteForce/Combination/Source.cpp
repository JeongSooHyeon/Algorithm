#include <iostream>
#include <vector>
using namespace std;

int n;
int r;

void Print(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] + 1 << ' ';
	cout << endl;
}

void allCombination(vector<int>& v, vector<bool>& visited) {
	if (v.size() == r) {
		Print(v);
		return;
	}

	int firstNum = -1;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			firstNum = i;
			visited[i] = true; 
			break;
		}
	}
	if (firstNum == -1)
		return;

	for (int i = firstNum; i < n; ++i) {
		v.push_back(i);
		allCombination(v, visited);
		v.pop_back();
	}

}

int main() {

	cin >> n >> r;
	vector<int> v;
	vector<bool> visited(n, false);

	allCombination(v, visited);
}