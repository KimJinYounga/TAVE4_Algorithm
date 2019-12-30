#include <stdio.h>

int memo[12];

int dp(int x) {
	// 초기값 입력
	memo[1] = 1;	// 1
	memo[2] = 2;	// 2 | 1 + 1
	memo[3] = 4;	// 3 | 2 + 1 | 1 + 2 | 1 + 1 + 1

	// 점화식 
	for(int i = 4; i <= x; i++) {
		memo[i] = memo[i-3] + memo[i-2] + memo[i-1];
	}
	
	return memo[x];
}

int main() {
	int test;
	scanf("%d", &test);
	

	int n;
	for(int i = 0; i < test; i++) {
		scanf("%d", &n);
		
		printf("%d\n", dp(n));
	}
	return 0;
}
