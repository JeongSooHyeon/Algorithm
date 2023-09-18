/*
와일드 카드
*/
#include <iostream>
#include <vector>
using namespace std;


int cache[101][101];
string W, S;

bool matchMemoized(int w, int s) {
	// 메모이제이션
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	// W[s]와 S[s]를 맞춰 나간다.
	while (s < S.size() && w < W.size() &&
		(W[w] == '?' || W[w] == S[s])) {
		++s;
		++w;
	}
	// 반복문 없애기
	if (w < W.size() && s < S.size() &&
		(W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized(w + 1, s + 1);




	if (w == W.size())
		return ret = (s == S.size());




	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); skip++) {
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
		}
	}
	// 반복문 없애기
	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) ||	// 대응 시키지 않을 것인지
			(s < S.size() && matchMemoized(w, s + 1)))	// 한 글자를 더 대응시킬 것인지 결정
			return ret = 1;
	}

	return ret = 0;
}

string w;	// 와일드카드 패턴
int n;	// 파일명의 수 1<=n<=50
vector<string> v(50);

// ? : 아무 글자, * : 0글자 이상의 아무 문자열
bool match(const string& w, const string& s) {
	// w[pos]와 s[pos]를 맞춰나간다
	int pos = 0;
	while (pos < s.size() && pos < w.size() &&
		(w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	// 더이상 대응할 수 없으면 왜 while문이 끝났는지 확인
	// 1. w[pos]와 s[pos]가 대응되지 않음 - 대응 실패
	// 2. w 끝에 도달 - *이 하나도 없는 경우, 패턴과 문자열의 길이가 같아야 대응
	if (pos == w.size())
		return pos == s.size();

	// 3. s 끝에 도달 - 남은 패턴이 *면 대응(4번에서 처리)
	// 4. s[pos]가 * - 몇 글자 대응되는지 0부터 남은 문자열의 길이까지 순회
	// w의 pos+1 이후 패턴, s의 pos+skip 이후 문자열 match()
	if (w[pos] == '*') {
		for (int skip = 0; pos + skip < s.size(); skip++) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}

	// 이 외의 경우 모두 대응되지 않음
	return false;

}



int main() {
	int c;
	cin >> c;


	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> w;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			// match();
		}
	}

}

