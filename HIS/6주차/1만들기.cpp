#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1000001];

int main() {
	cin >> N;
	arr[1] = 0;
	// i번째 원소를 저장해두고, 그 값을 기반으로 다음 값을 구하는 과정
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		// 여기 비교를 2번 하는게 살짝 고민됬는데, 다른 방법은 생각이 안남
		if (i % 2 == 0)
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		if (i % 3 == 0)
			arr[i] = min(arr[i / 3] + 1, arr[i]);
	}
	cout << arr[N] << endl;
}