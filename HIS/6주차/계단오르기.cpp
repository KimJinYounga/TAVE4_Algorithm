#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[301];
int visited[301];

int main() {
	cin >> N;
	arr[0] = 0, visited[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		visited[i] = 0;
	}
	visited[1] = arr[1];
	visited[2] = arr[1] + arr[2];
	visited[3] = max(arr[1], arr[2]) + arr[3];
	for (int i = 4; i <= N; i++) {
		visited[i] = max(visited[i - 2] + arr[i], visited[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << visited[N] << endl;
}
/*
계단은 한 개 혹은 두 개 씩 오를 수 있다.
연속 세개는 불가하다
마지막 계단은 무조건 밟아야한다.
총 점수 최댓값은?
*/