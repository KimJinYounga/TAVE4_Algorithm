#include "iostream"
#include "queue"

using namespace std;

// 입력 : 총 인원(N), 현재 위치 기준 K번 째 사람(K)
// 출력 : 조세피스 순열에 의한 결과 
/*
	<따져야 될 것> 
	1. 큐를 어떤 방식으로 순환을 할지
*/

void permutation(int n, int k);

int main() {
	int n, k;
	
	// 총 인원 n 입력 
	cin >> n;

	// 배수 k 입력 
	cin >> k;
	
	permutation(n, k);
	
	return 0;
}

void permutation(int n, int k) {
	queue<int> q;
	
	int i, j;
	
	for(i = 1; i <= n; i++) {
		q.push(i);
	}
		
	
	cout << '<';
	
	for(j = 0; j < k - 1; j++) {
		q.push(q.front());
		q.pop();
	}
	
	cout << q.front();
	q.pop();
	
	for(i = 1; i < n; i++) {
		for(j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << ", ";
		cout << q.front();

		q.pop();
	}
	cout << '>' << endl;
}



