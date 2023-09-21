/*
광학 문자 인식 문제를 해결하는 동적 계획법 알고리즘
*/
#include <iostream>
#include <cmath>
using namespace std;

int n, m;	// 검사한 문장의 단어의 수 1<=n<=100, 원문에 출현할 수 있는 단어의 수
// 입력받은 단어들의 목록
string corpus[501];
// 분류기가 반환한 문장. 단어 번호로 변환되어 있음
int R[100];
// T[i][j] = i 단어 이후에 j 단어가 나올 확률의 로그값
double T[501][501];
// M[i][j] = i 단어가 j 단어로 분류될 확률의 로그 값
double M[501][502];
int choice[102][502];
double cache[102][502];	// 1로 초기화
double B[501];	// 해당 단어가 첫단어로 올 확률

// Q[segment] 이후를 채워서 얻을 수 있는 최대 g() 곱의 로그값을 반환
// Q[segment-1] == previousMatch라고 가정
double recognize(int segment, int previousMatch) {
	// 기저 사례 : 문장 끝까지 검사
	if (segment == n)	return 0;

	// 메모이제이션
	double& ret = cache[segment+1][previousMatch+1];
	if (ret != 1.0)	return ret;

	ret = -1e200;	// log(0) = 음의 무한대에 해당하는 값
	int& choose = choice[segment+1][previousMatch+1];

	// R[segment]에 대응되는 단어를 찾는다.
	for (int thisMatch = 0; thisMatch < m; thisMatch++) {
		// g(thisMatch) = T(previousMatch, thisMatch) * M(thisMatch, R[segment])
		// 이전 단어의 다음으로 현 단어일 확률 * 원래 단어를 변환된 단어로 분류할 확률
		double cand = 0.0;
		// 확률의 로그값의 합
		if (previousMatch == -1) {
			cand = log(B[R[0]]) + log(M[thisMatch][R[segment]])
				+ recognize(segment + 1, thisMatch);
		}
		else
			cand = log(T[previousMatch][thisMatch]) + log(M[thisMatch][R[segment]]) 
			+ recognize(segment + 1, thisMatch);

		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment+1][previousMatch+1];
	string ret = corpus[choose];
	if (segment < n-1)
		ret = ret + " " + reconstruct(segment+1, choose);
	return ret;
}

int main() {
	//int m;	// 원문에 출현할 수 있는 단어의 수 1<=m<=500
	int q;	// 처리해야 할 문장의 수 1<=q<=100
	cin >> m >> q;
	
	for (int i = 0; i < m; i++) {
		cin >> corpus[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];	// i번 단어가 첫 단어로 출현할 확률
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> T[i][j];	// i번 단어의 다음 단어가 j번 단어일 확률
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];	// i번 단어가 적힌 조각을 j번 단어로 분류할 확률
		}
	}

	string temp;
	for (int i = 0; i < q; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			for (int k = 0; k < m; k++) {
				if (temp == corpus[k]) {
					R[j] = k;
					break;
				}
			}
		}

		fill(&cache[0][0], &cache[0][0]+102*502, (double)1.0);
		//recognize(1, 0);
		cout << "확률 : " << recognize(0, -1) << endl;
		
		cout << reconstruct(0, -1) << " ";

		cout << endl;
	}
}