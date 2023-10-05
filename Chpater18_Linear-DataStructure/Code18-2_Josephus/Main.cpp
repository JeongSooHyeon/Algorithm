#include <iostream>
#include <list>
using namespace std;

int n, k;	// 3<=n, k<=1000	// k번째 사람이 자살

// 마지막 살아남는 두 사람의 번호 오름차순
void Josephus(int n, int k) {
	// 리스트 준비
	list<int> survivors;
	for (int j = 0; j < n; j++) {
		survivors.push_back(j + 1);
	}

	// 이번에 죽을 사람
	list<int>::iterator kill = survivors.begin();
	while (n > 2) {
		// 첫 번째 사람이 자살, erase()는 지운 원소의 다음 원소 반환
		kill = survivors.erase(kill);
		if (kill == survivors.end()) {	// 끝에 도달
			kill = survivors.begin();	// 처음으로 돌아가
		}
		--n;

		// k-1번 다음 사람으로 옮긴다.
		for (int i = 0; i < (k - 1) % n; i++) {
			if (++kill == survivors.end())
				kill = survivors.begin();
		}
	}
	cout << survivors.front() << ' ' << survivors.back() << endl;
}



int main() {
	int c;	// 테스트 케이스
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> k;

		Josephus(n ,k);
	}

	return 0;
}