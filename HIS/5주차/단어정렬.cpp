#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;

bool comp(string a, string b) {
	// 두 변수의 길이가 같은경우 사전순으로 반환
	if (a.size() == b.size())
		return a < b;
	// 두 변수의 길이가 다른경우 길이순으로 반환
	return a.size() < b.size();
}

int main() {
	int N;
	string tempS;
	cin >> N;
	// 입력부분
	for (int i = 0; i < N; i++) {
		cin >> tempS;
		v.push_back(tempS);
	}

	// 정렬 라이브러리 사용
	// comp는 정렬 규칙 함수
	sort(v.begin(), v.end(), comp);

	// 중복 제외하고 출력
	for (int i = 0; i < v.size(); i++) {
		if (i > 0 && v[i - 1] == v[i])
			continue;
		cout << v[i] << endl;
	}
}