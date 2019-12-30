#include<iostream>
using namespace std;
int T, a, b, ans = 0;

/*
100명 중 21명에게 6등까지 1 2 3 4 5 6
64명 중 31명에게 5등까지 1 2 4 8 16
*/
int arr17[8] = { 0, 1, 3, 6, 10, 15, 21, 100 };
int price17[8] = { 0, 500, 300, 200, 50, 30, 10, 0 };
// 0 & 1 & 2, 3 && 4 5 6 && 7 8 9 10 && 11 12 13 14 15 && ...
int arr18[7] = { 0, 1, 3, 7, 15, 31, 64 };
int price18[7] = { 0, 512, 256, 128, 64, 32, 0 };
// 0 && 1 && 2 3 && 4 5 6 7 && 8 9 10 11 12...

// 두번째~-2원소는 arr[i-1]+1 ~ arr[i]범위 등수
// -1원소는 입상치 못한 arr[i-1]~arr[i]범위 등수

void check() {
	if (a == 0)
		ans += price17[0];
	else{
		for (int i = 1; i < 8; i++) {
			if (arr17[i - 1] <= a && a <= arr17[i]) {
				ans += price17[i];
				break;
			}
		}
	}
	if (b == 0)
		ans += price18[0];
	else{
		for (int i = 1; i < 7; i++) {
			if (arr18[i - 1] <= b && b <= arr18[i]) {
				ans += price18[i];
				break;
			}
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		ans = 0;
		check();
		cout << ans * 10000 << endl;
	}
}