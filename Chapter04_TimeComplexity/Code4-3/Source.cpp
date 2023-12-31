/*
4.3 이동 평균 구하기
*/

#include <iostream>
#include <vector>
using namespace std;

// 실수 배열 A가 주어질 때, 각 위치에서의 M-이동 평균 값을 구한다.
vector<double> movingAverage1(const vector<double>& A, int M) {
    vector<double> ret;
    int N = A.size();   // 10
    for (int i = M - 1; i < N; ++i) {   // 2 3 4...
        // A[i]까지의 이동 평균 값을 구하자.
        double partialSum = 0;
        for (int j = 0; j < M; ++j)
            partialSum += A[i - j]; // 210 321 432...
        ret.push_back(partialSum / M);
    }
    return ret;
}