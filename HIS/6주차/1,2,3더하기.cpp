#include<iostream>
using namespace std;
int T, N; // n < 11
int arr[11];
/*
1부터 5까지 모두 적어보고나서야 규칙을 찾았습니다..
이거 어떻게 머릿속으로 그림.. 개쩜 짝짝짝
*/

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;
		// 이전 3개를 합친게 답입니다.
		for (int j = 4; j <= N; j++)
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		cout << arr[N] << endl;
	}
}

/*
1 : 1
1

2 : 2 
1 1
2

3 : 4
1 1 1
1 2	
2 1
3

4 : 7
1 1 1 1
1 1 2
1 2 1
2 1 1
2 2
1 3
3 1

5 : 13
1 1 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1
2 1 1 1
1 2 2
2 1 2
2 2 1
1 1 3
1 3 1
3 1 1
2 3
3 2
*/