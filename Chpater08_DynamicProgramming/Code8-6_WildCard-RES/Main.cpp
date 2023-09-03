/*
와일드카드 문제를 해결하는 완전 탐색 알고리즘
*/
#include <iostream>
#include <vector>
using namespace std;



int match(const string& w, const string& s) {
	// w[pos]와 s[pos]를 맞춰나간다.
	int pos = 0;
	while (pos < s.size() && pos < w.size() &&
		(w[pos] == '?' || w[pos] == s[pos])) {	// *를 만나거나, 둘 중 한 문자열이 끝날 때 멈춤
		++pos;
	}	// 더이상 대응할 수 없으면 왜 while문이 끝났는지 확인

	// 패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 대응됨
	if (pos == w.size())
		return pos == s.size();

	// *를 만나서 끝난 경우 : *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인
	if (w[pos] == '*') {
		for (int skip = 0; pos + skip <= s.size(); ++skip) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}

	// 이 외의 경우에는 모두 대응되지 않는다
	return false;

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