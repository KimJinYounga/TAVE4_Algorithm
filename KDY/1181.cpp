#include <iostream>
#include <algorithm>

using namespace std;

string str[20000];

bool compare(string a, string b) {
	
	if(a.length() < b.length()) {
		return true;
	}
	else if(a.length() > b.length()) {
		return false;
	}
	else {
		return a < b;
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> str[i];
	}
	// 데이터 정렬
	sort(str, str + n, compare);
	
	for(int i = 0; i < n; i++) {
		// 중복된 문자가 나오면 출력 안하고 다음 반복문 실행 
		if(i > 0 && str[i] == str[i-1]) {
			continue;
		}
		else {
			cout << str[i] <<'\n';			
		}
	}
	return 0;
}
