#include <iostream>
#include <utility>		// pair 자료형 
#include <algorithm>

using namespace std;


typedef struct Student {
	string name;
	int a;		// 국어 
	int b;		// 영어 
	int c;		// 수학 
}Student;


bool compare(Student s1, Student s2) {
	if(s1.a != s2.a) {
		// 내림차순 정렬 
		return s1.a > s2.a;
	}
	// 국어 점수가 같으면 
	else {
		if(s1.b != s2.b) {
			// 오름차순 정렬 
			return s1.b < s2.b;
		}
		// 영어 점수가 같으면 
		else {
			if(s1.c != s2.c) {
				// 내림차순 정렬 
				return s1.c > s2.c;
			}
			else {
				// 사전 순
				return s1.name < s2.name;
			}
		}
	}
}


int main() {
	int n;

	cin >> n;

	Student student[n];
	for(int i = 0; i < n; i++) {
		cin >> student[i].name >> student[i].a >> student[i].b >> student[i].c;
	}
	
	sort(student, student + n, compare);
	
	for(int i =0; i < n; i++) {
		cout << student[i].name << '\n';
	}
	return 0;
}
