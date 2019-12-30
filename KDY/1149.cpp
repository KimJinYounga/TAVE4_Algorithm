#include <stdio.h>
#include <algorithm>

using namespace std;

// 3개 인자 값에 대한 최솟값을 구하기 
int minimum(const int x, const int y, const int z) {
	int temp = x;
	
	if(temp > y) {
		temp = y;
	}
	
	if(temp > z) {
		temp = z;
	}
	
	return temp;
}
	
int dp(int test) {
	
	// 경우의 수를 저장할 배열 
	int memo[3] = {0, };

	// 색깔 별 가격을 저장할 배열
	int RGB[3] = {0, };
		
	// 이전 RGB 비용을 기록할 배열 
	int pastRGB[3] = {0, };
	
	// 색깔 별 비용 입력
	scanf("%d %d %d", &RGB[0], &RGB[1], &RGB[2]);
	memo[0] = RGB[0];	memo[1] = RGB[1];	memo[2] = RGB[2];
	 
	for(int i = 1; i < test; i++) {
		// i - 1까지의 최소 비용 저장
		pastRGB[0] = memo[0];
		pastRGB[1] = memo[1];
		pastRGB[2] = memo[2];
		
		// 색깔 별 비용 입력
		scanf("%d %d %d", &RGB[0], &RGB[1], &RGB[2]);

		// i - 1번째 집과 i번쨰 집에 비용을 계산한 값을 memo에 저장  
		memo[0] = RGB[0] + min(pastRGB[1], pastRGB[2]);
		memo[1] = RGB[1] + min(pastRGB[0], pastRGB[2]);
		memo[2] = RGB[2] + min(pastRGB[0], pastRGB[1]);		
	}
	
	// 최솟값 return	
	return minimum(memo[0], memo[1], memo[2]);
}

int main() {
	// 초기 변수 선언 및 초기화 
	int test = 0;

	// test 개수 입력
	scanf("%d", &test);
	
	// 최솟값 출력 
	printf("%d", dp(test));
}
