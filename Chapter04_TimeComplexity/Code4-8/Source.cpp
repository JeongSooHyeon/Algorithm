/*
4.8 선택 정렬과 삽입 정렬
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
		// a[0..i-1]에 a[i]를 끼워 넣는다.
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			swap(a[j - 1], a[j]);
			--j;
		}
	}
}