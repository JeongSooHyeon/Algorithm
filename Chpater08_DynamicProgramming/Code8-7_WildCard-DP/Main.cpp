/*
와일드카드 문제를 해결하는 동적 계획법 알고리즘
*/
#include <iostream>
#include <vector>
using namespace std;

int cache[101][101];	// -1:답이 계산되지 않음, 1:입력들이 서로 대응됨, 0:입력들이 서로 대응되지 않음

// 패턴과 문자열
string W, S;

// 와일드카드 패턴 W[w..]가 문자열 S[s..]에 대응되는지 여부를 반환
int matchMemoized(int w, int s) {	// 두 문자열의 시작 위치
	// 메모이제이션
	int& ret = cache[w][s];
	if (ret != -1)
		return ret;

	// W[w]와 S[s]를 맞춰나간다.
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}	// 더이상 대응할 수 없으면 왜 while문이 끝났는지 확인

	// 패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 대응됨
	if (w == W.size())
		return ret = (s == S.size());

	// *를 만나서 끝난 경우 : *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인
	if (W[w] == '*') {
		for (int skip = 0; s + skip <= S.size(); ++skip) {
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
		}
	}
}

int main() {
	int c;	// 테스트 케이스 수 1 <= c < 10
	cin >> c;
	string pattern;

	for (int i = 0; i < c; i++) {
		cin >> pattern;
		int n = -1;	// 파일 명의 수 1 <= n <= 50
		cin >> n;

		string fileName;


		for (int j = 0; j < n; j++) {
			cin >> fileName;
			// 함수 호출
			match(pattern, fileName);
		}

	}

	return 0;
}