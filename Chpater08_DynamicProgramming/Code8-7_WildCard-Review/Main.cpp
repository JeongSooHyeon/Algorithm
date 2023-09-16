/*
와일드 카드
*/
#include <iostream>
#include <vector>
using namespace std;


int cache[100][100];

string w;	// 와일드카드 패턴
int n;	// 파일명의 수 1<=n<=50
vector<string> v(50);

// ? : 아무 글자, * : 0글자 이상의 아무 문자열
void wildCard() {
	// 기저 사례 : 

	// 메모이제이션

	// 계산
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
			wildCard();
		}
	}

}

