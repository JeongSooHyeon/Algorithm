#include <iostream>
#include <queue>
using namespace std;

int n, k;	// 3<=n, k<=1000	// k번째 사람이 자살

// 마지막 살아남는 두 사람의 번호 오름차순
void Josephus(int n, int k) {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	while (q.size() > 2) {
		q.pop();	// 첫번째 사람 뽑기
		for (int i = 0; i < k - 1; i++) {	// k-1번 옮기기
			int temp = q.front();	// 맨 앞사람
			q.pop();	// 뽑아서
			q.push(temp);	// 뒤에 붙이기
		}
	}
}



int main() {
	int c;	// 테스트 케이스
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> k;

		Josephus(n, k);
	}

	return 0;
}