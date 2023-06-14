/*
4.8 ���� ���İ� ���� ����
*/

#include <iostream>
#include <vector>
using namespace std;

void selectSort(vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		int minIndex = i;
		for (int j = i + 1; j < a.size(); ++j)
			if (a[minIndex] > a[j])
				minIndex = j;
		swap(a[i], a[minIndex]);
	}
}

void insertionSort(vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		// a[0..i-1]�� a[i]�� ���� �ִ´�.
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			swap(a[j - 1], a[j]);
			--j;
		}
	}
}