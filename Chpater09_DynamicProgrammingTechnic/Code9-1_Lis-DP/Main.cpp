/*
최대 증가 부분 수열을 실제로 계산하기
*/
#include <iostream>
#include <vector>
using namespace std;


int n = 5;
int cache[101], s[100], choices[101];
// s[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환
int lis4(int start) {
	int& ret = cache[start + 1];	// start=-1이 주어질 수 있기 때문
	if (ret != -1)
		return ret;

	// 항상 s[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	int bestNext = -1;	// 어떤 선택지를 택했는지
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || s[start] < s[next]) {
			int cand = lis4(next) + 1;
			if (cand > ret) {
				ret = cand;
				bestNext = next;
			}
		}
	}
	choices[start + 1] = bestNext;
	return ret;
}

// s[start]에서 시작하는 LIS를 seq에 저장
void reconstruct(int start, vector<int>& seq) {
	if (start != -1)
		seq.push_back(s[start]);
	int next = choices[start + 1];
	if (next != -1)
		reconstruct(next, seq);
}

int main() {
	memset(cache, -1, sizeof(cache));
	s[0] = 1;
	s[1] = 2;
	s[2] = 4;
	s[3] = 3;
	s[4] = 4;

	cout << lis4(-1) - 1 << endl;

	vector<int> result;
	reconstruct(-1, result);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';

	return 0;
}