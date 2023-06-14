/*
6.2 n���� ���� �� m���� ���� ��� ������ ã�� �˰���
*/

#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector<int>&);

// n : ��ü ������ ��
// picked : ���ݱ��� �� ���ҵ��� ��ȣ
// toPick : �� �� ������ ��
// �� ��, ������ toPick���� ���Ҹ� ���� ��� ����� ����Ѵ�.
void pick(int n, vector<int>& picked, int toPick) {
	// ���� ��� : �� �� ���Ұ� ���� �� �� ���ҵ��� ���
	if (toPick == 0) {
		printPicked(picked);
		return;
	}
	// �� �� �ִ� ���� ���� ��ȣ�� ���
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// �� �ܰ迡�� ���� �ϳ��� ����.
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}