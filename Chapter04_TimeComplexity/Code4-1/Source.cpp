/*
4.1 �־��� �迭���� ���� ���� �����ϴ� ���ڸ� ��ȯ�ϱ�
*/

#include <iostream>
#include <vector>
using namespace std;

// �־��� �迭 A���� ���� ���� �����ϴ� ���ڸ� ��ȯ�Ѵ�.
// ���� �� ���� �̻� ���� ��� �ƹ����̳� ��ȯ�Ѵ�.
int majority1(const vector<int>& a) {
    int n = a.size();
    int majority = -1, majorityCount = 0;
    for (int i = 0; i < n; ++i) {
        // a�� �����ϴ� a[i]�� ���� ����.
        int v = a[i], count = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == v)
                ++count;
        }
        // ���ݱ��� �� �ִ� �󵵺��� ���� �����ߴٸ� ���� �����Ѵ�.
        if (count > majorityCount) {
            majorityCount = count;
            majority = v;
        }
    }
    return majority;
}