#include <iostream>
using namespace std;

int cache[101][101];	

string W;	// 패턴
int n;	// 파일명의 수 
string S;	// 파일명

// 패턴의 인덱스, 파일명의 인덱스
bool match(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1)	return ret;

	//while (w < W.size() && s < S.size() && 
	//		(W[w] == S[s] || W[w] == '?')) {
	//	w++;
	//	s++;
	//}
	if (w < W.size() && s < S.size() &&
		(W[w] == S[s] || W[w] == '?')) {
		return ret = match(w + 1, s + 1);
	}

	// 왜 while문을 나갔는지 확인
	if (w == W.size()) {	// 패턴 끝까지
		return ret = s == S.size();	// 문자열도 끝까지
	}

	// *라면 어디까지 포함해야 하는지 검사
	if (W[w] == '*') {
		//for(int skip = 0; skip + s <= S.size(); skip++) {
		//	if (match(w + 1, skip + s)) {	
		//		return ret = 1;
		//	}
		//}

		if ((s < S.size() && match(w, s + 1)) 
			|| match(w + 1, s))
			return ret = 1;
	}

	return false;
}

int main() {
	int c;	// 테스트 케이스
	cin >> c;



	for (int i = 0; i < c; i++) {
		cin >> W;	// 패턴
		cin >> n;	// 1<=n<=50
		for (int j = 0; j < n; j++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;	// 1<=s<=100
			// 함수 호출
			if (match(0, 0))
				cout <<"모스 " << S << endl;
		}
	}

	return 0;
}