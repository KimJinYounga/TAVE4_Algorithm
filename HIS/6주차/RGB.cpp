#include<iostream>
using namespace std;
int N;
int arr[1001][3];
int visited[1001][3];

int min2(int a, int b) {
	if (a > b) return b;
	else return a;
}
int min3(int a, int b, int c) {
	if (a > b) {
		if (b > c) return c;
		else return b;
	}
	else {
		if (a > c) return c;
		else return a;
	}
}

/*이건 왜 에러였을까
int min3(int a, int b, int c) {
	if (a > b) {
		if (b > c) return c;	// abc
		else return b;			// acb or cab
	}
	else if (b > a) {
		if (a > c) return c;	// bac
		else return a;			// bca or cba
	}
	else if (c > b) {			// 여기는 무의미한 중복까지 발생
		if (b > a) return a;	// cba
		else return b;			// cab or acb
	}
	// 같은 경우 반환이 안되서 틀렸다.
	// 위에서는 else에 모두 포함된다.
}
*/

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	visited[0][0] = arr[0][0];
	visited[0][1] = arr[0][1];
	visited[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		visited[i][0] = min2(visited[i - 1][1], visited[i - 1][2]) + arr[i][0];
		visited[i][1] = min2(visited[i - 1][0], visited[i - 1][2]) + arr[i][1];
		visited[i][2] = min2(visited[i - 1][0], visited[i - 1][1]) + arr[i][2];
	}
	cout << min3(visited[N - 1][0], visited[N - 1][1], visited[N - 1][2]) << endl;
}