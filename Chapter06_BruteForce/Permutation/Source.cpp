#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i]+1 << ' ';
	cout << endl;
}

void allPermutation(int n, vector<int>& v, vector<bool>& visited) {
	for (int i = n-1; i >= 0; --i) {
		if (visited[i])
			continue;
		v.push_back(i);
		visited[i] = true;
		allPermutation(n, v, visited);
		visited[i] = false;
		v.pop_back();
	}
		if(v.size() ==n)
			Print(v);
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	vector<bool> visited(n, false);

	allPermutation(n, v, visited);
}