#include "iostream"
#include "stack"

using namespace std;

// 입력 : 괄호 
// 출력 :  잘린 쇠막대기 조각의 개수 
// 최대 time cost : 1초
// 최대 memory cost : 256MB
/*
	<따져야 될 것>
	1. 문자열 검사를 할 때 괄호 형태가 '레이저'인지 확인 => 스택에 괄호를 넣는 것이 아닌 인덱스를 넣음으로써 확인하기
	2. 레이저로 쇠 막대기를 자를 때, 총 잘린 쇠막대기 조각 개수를 어떻게 계산할지 
*/
int counting(string str);

int main() {
	string input_value;
	
	cin >> input_value;
	
	cout << counting(input_value) << endl;
	
	return 0;
}

int counting(string str) {
	stack<int> s;		// 인덱스(index)를 저장할 자료형
	int cnt = 0;		// 총 쇠막대기 개수를 저장할 변수
	
	// ()(((()())(())()))(())
	for(int i = 0; i < str.length(); i++) {
		if(str.at(i) == '(') {
			s.push(i);
		}
		else {
			// 레이저이면 
			if((i - 1) == s.top()) {
				s.pop();
				cnt += s.size();
			}
			// 쇠막대기의 마지막이면
			else {
				s.pop();
				cnt += 1;
			}
		}
	}
	
	return cnt;
}


