/*
5.2 (불변식이 추가된) 삽입 정렬 알고리즘
*/

#include <iostream>
#include <vector>
using namespace std;

void insertionsSort(vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		// 불변식 a : a[0..i-1]은 이미 정렬되어 있다.
		// a[0..i-1]에 a[i]를 끼워넣는다.
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			// 불변식 b : a[j+1..i]의 모든 원소는 a[j]보다 크다
			// 불변식 c : a[0..i] 구간은 a[j]를 제외하면 정렬되어 있다.
			swap(a[j - 1], a[j]);
			--j;
		}
	}
}