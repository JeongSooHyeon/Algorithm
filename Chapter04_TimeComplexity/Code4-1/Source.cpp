/*
4.1 주어진 배열에서 가장 많이 등장하는 숫자를 반환하기
*/

#include <iostream>
#include <vector>
using namespace std;

// 주어진 배열 A에서 가장 많이 등장하는 숫자를 반환한다.
// 만약 두 가지 이상 있을 경우 아무것이나 반환한다.
int majority1(const vector<int>& a) {
    int n = a.size();
    int majority = -1, majorityCount = 0;
    for (int i = 0; i < n; ++i) {
        // a에 등장하는 a[i]의 수를 센다.
        int v = a[i], count = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == v)
                ++count;
        }
        // 지금까지 본 최대 빈도보다 많이 출현했다면 답을 갱신한다.
        if (count > majorityCount) {
            majorityCount = count;
            majority = v;
        }
    }
    return majority;
}