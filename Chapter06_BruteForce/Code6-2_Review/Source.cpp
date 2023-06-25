#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}
void pick(int n, int toPick, vector<int>& v) {
	// ���� ��� : �� ��
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
	int n;	// �־��� ���� ����
	int m;	// ���� �� ���� ����
	vector<int> v;	// �� ���ҵ�
	
	cin >> n >> m;

	pick(n, m, v);
}