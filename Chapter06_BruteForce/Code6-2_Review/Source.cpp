#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}
void pick(int n, int toPick, vector<int>& v) {
	// 기저 사례 : 다 고름
	if (toPick <= 0) {
		Print(v);
		return;
	}
	int toPickNum;
	if (v.empty())
		toPickNum = 0;
	else
		toPickNum = v.back() + 1;

	for (int i = toPickNum; i < n; ++i) {
		v.push_back(i);
		pick(n, toPick - 1, v);
		v.pop_back();
	}
}

int main() {
	int n;	// 주어진 원소 개수
	int m;	// 골라야 할 원소 개수
	vector<int> v;	// 고른 원소들
	
	cin >> n >> m;

	pick(n, m, v);
}