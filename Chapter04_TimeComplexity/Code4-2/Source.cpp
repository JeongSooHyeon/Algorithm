/*
4.2 �־��� �迭���� ���� ���� �����ϴ� ���ڸ� ��ȯ�ϱ�2
*/

#include <iostream>
#include <vector>
using namespace std;

// a�� �� ���Ұ� 0���� 100������ ���� ��� ���� ���� �����ϴ� ���ڸ� ��ȯ
int majority2(const vector<int>& a) {
    int n = a.size();
    vector<int> count(101, 0);
    for (int i = 0; i < n; ++i) {
        count[a[i]]++;
    }
    // ���ݱ��� Ȯ���� ���� �� �󵵼��� ���� ū ���� majority�� �����Ѵ�.
    int majority = 0;
    for (int i = 1; i <= 100; ++i) {
        if (count[i] > count[majority])
            majority = i;
    }
    return majority;
}