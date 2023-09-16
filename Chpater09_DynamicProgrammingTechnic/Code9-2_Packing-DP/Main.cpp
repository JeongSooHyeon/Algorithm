/*

*/
#include <iostream>
#include <vector>
using namespace std;

int n;	// 가져가고 싶은 물건의 수 1<=n<=100
int w;	// 캐리어 용량 1<=w<=1000
string name[100];	// 물건 이름 
int volume[100], need[100];	// 물건 부피, 절박도 <=1000

int cache[1001][101];
int choices[101];
// 캐리어에 남은 용량이 capacity일 때, item 이후의 물건들을
// 담아 얻을 수 있는 최대 절박도의 합 반환
int pack(int capacity, int item) {	
	// 기저 사례 : 더 담을 물건이 없을 때
	if (item == n)	return 0;

	// 메모이제이션
	int ret = cache[capacity][item];
	if (ret != -1)	return ret;

	// 이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);

	// 이 물건을 담을 경우
	if (capacity >= volume[item]) {
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	}
	
	return ret;
}

// pack(capacity, item)이 선택한 물건들의 목록을 picked에 저장
void reconstruct(int capacity, int item, vector<string>& picked) {
	// 기저 사례 : 모든 물건을 다 고려했음
	if (item == n)	return;

	if (pack(capacity, item) == pack(capacity, item + 1)) {	// item은 선택되지 않은 것
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	int c;	// 테스트 케이스
	cin >> c;

	for (int i = 0; i < c; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> w;
		for (int j = 0; j < n; j++) {
			cin >> name[j] >> volume[j] >> need[j];	// 이름, 부피, 절박도
		}
		// 함수 호출
		cout << pack(w, 0) << ' ';
		vector<string> picked;
		reconstruct(w, 0, picked);
		cout << picked.size() << endl;
		for (int i = 0; i < picked.size(); i++)
			cout << picked[i] << endl;
	}

	return 0;
}