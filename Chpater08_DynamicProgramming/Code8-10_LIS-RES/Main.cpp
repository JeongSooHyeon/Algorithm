/*
�ִ� ���� �κ� ���� ������ �ذ��ϴ� ���� Ž�� �˰���
*/
#include <iostream>
#include <vector>
using namespace std;


int lis(const vector<int>& a) {
	// ���� ��� : A�� �� ������� ��
	if (a.empty())
		return 0;
	int ret = 0;
	for (int i = 0; i < a.size(); i++) {
		vector<int> b;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[i] < a[j])
				b.push_back(a[j]);
		}
		ret = max(ret, 1 + lis(b));
	}
	return ret;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);
	a.push_back(4);

	cout << lis(a);


	return 0;
}