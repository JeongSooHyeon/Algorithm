/*
4.7 ���� Ž��
*/

#include <iostream>
#include <vector>
using namespace std;

// array[i] = element�� ù i�� ��ȯ. ������ -1 ��ȯ
int firstIndex(const vector<int>& array, int element) {
	for (int i = 0; i < array.size(); ++i)
		if (array[i] == element)
			return i;
	return -1;
}