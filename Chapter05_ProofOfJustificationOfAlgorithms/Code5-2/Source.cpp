/*
5.2 (�Һ����� �߰���) ���� ���� �˰���
*/

#include <iostream>
#include <vector>
using namespace std;

void insertionsSort(vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		// �Һ��� a : a[0..i-1]�� �̹� ���ĵǾ� �ִ�.
		// a[0..i-1]�� a[i]�� �����ִ´�.
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			// �Һ��� b : a[j+1..i]�� ��� ���Ҵ� a[j]���� ũ��
			// �Һ��� c : a[0..i] ������ a[j]�� �����ϸ� ���ĵǾ� �ִ�.
			swap(a[j - 1], a[j]);
			--j;
		}
	}
}